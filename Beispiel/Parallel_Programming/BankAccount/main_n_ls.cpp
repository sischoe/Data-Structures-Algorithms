#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <cassert>

using mutex = std::recursive_mutex;
using guard = std::lock_guard<mutex>;

class BankAccount {
  int balance = 0;
  unsigned id;
public:
  mutex m;
  
public:
  BankAccount(unsigned num): id{num} {}
  BankAccount(BankAccount&& a){
      id = a.id;
      balance = a.balance;
  };
  int Id(){
      return id;
  }
  
  int  getBalance(){
    guard g(m); return balance; 
  }
  
  void setBalance(int x) {
    guard g(m); balance = x; 
  } 
  
  void withdraw(int amount) {
    guard g(m);
    int b = getBalance();
    setBalance(b - amount);
  }
  
  void deposit(int amount){
      guard g(m);
      int b = getBalance();
      setBalance(b + amount);
  }
  
  void transfer(int amount, BankAccount& to){
    withdraw(amount);
    to.deposit(amount);
  }
};

using BankAccounts = std::vector<BankAccount>;

void simulate(BankAccounts &accounts, unsigned numberTransfers){
  std::random_device rd;
	std::default_random_engine e1(rd());
	std::uniform_int_distribution<int> uniform(0,accounts.size()-1);

    for (unsigned i = 0; i<numberTransfers; ++i){
        BankAccount& from = accounts[uniform(e1)];
        BankAccount& to = accounts[uniform(e1)];
        int amount = uniform(e1);
        from.transfer(amount, to);
    }
}

void check(BankAccounts &accounts, unsigned numberChecks){
    for (unsigned i = 0; i<numberChecks; ++i){
      for (auto& account: accounts){
        account.m.lock(); 
      }
      int sum = 0; 
      for (auto& account: accounts){
        sum += account.getBalance(); 
      }
      assert(sum == 0);
      for (auto& account: accounts){
        account.m.unlock(); 
      }
    }
}

int main(){
    unsigned numberAccounts = 5;
    unsigned numberThreads = 2;
    unsigned numberTransfers = 100;
    unsigned numberChecks = 0;
    std::cout << "numberAccounts " << std::endl;
    std::cin >> numberAccounts;
    std::cout << "numberThreads " << std::endl;
    std::cin >> numberThreads;
    std::cout << "numberTransfers " << std::endl;
    std::cin >> numberTransfers;
    std::cout << "numberChecks " << std::endl;
    std::cin >> numberChecks;
    
    std::vector<BankAccount> accounts;
    std::vector<std::thread> threads;
    for (unsigned id = 0; id < numberAccounts; ++id){
        accounts.push_back(BankAccount{id});
    }
    std::thread checker(check,std::ref(accounts),numberChecks);
    for (unsigned id = 0; id < numberThreads; ++id){
        threads.push_back(std::thread(simulate, std::ref(accounts), numberTransfers));
    }
    for (auto & t: threads)
        t.join();
    checker.join();
    int sum = 0;
    for (auto & b: accounts){
        std::cout << b.Id() << ":" << b.getBalance() << std::endl;
        sum += b.getBalance();
    }
    std::cout << "sum=" << sum;
        
	return 0;
}
