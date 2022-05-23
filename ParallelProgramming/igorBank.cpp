#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>

class BankAccount {
  int balance = 0;
  int id;

public:
  igorBank(int num): id{num} {}
  igorBank(igor&& a){
      id = a.id;
      balance = a.balance;
  };
  int Id(){
      return id;
  }
  
  int  getBalance(){return balance; }
  void setBalance(int x) {balance = x; } 
  
  void withdraw(int amount) {
    int b = getBalance();
    setBalance(b - amount);
  }
  
  void deposit(int amount){
      int b = getBalance();
      setBalance(b + amount);
  }
  
  void transfer(int amount, BankAccount& to){
      withdraw(amount);
      to.deposit(amount);
  }
  
};

using BankAccounts = std::vector<igorBank>;

void simulate(BankAccounts &accounts){
    std::random_device rd;
	std::default_random_engine e1(rd());
	std::uniform_int_distribution<int> uniform(0,accounts.size()-1);

    for (int i = 0; i<1000; ++i){
        igorBank& from = accounts[uniform(e1)];
        igorBank& to = accounts[uniform(e1)];
        int amount = uniform(e1);
        from.transfer(amount, to);
    }
}

int main(){

    std::vector<igorBank> accounts;
    std::vector<std::thread> threads;
    for (int id = 0; id < 5; ++id){
        accounts.push_back(igorBank{id});
    }
    for (int id = 0; id < 5; ++id){
        threads.push_back(std::thread(simulate, std::ref(accounts)));
    }
    for (auto & t: threads)
        t.join();
    
    int sum = 0;
    for (auto & b: accounts){
        std::cout << b.Id() << ":" << b.getBalance() << std::endl;
        sum += b.getBalance();
    }
    std::cout << "sum (should be zero) =" << sum;
        
	return 0;
}
