#include <iostream>
#include <thread>
#include <vector>
#include <sstream>

void hello(int id){
  std::cout << "hallo" << "von " << id << std::endl;
}

int main(){
  unsigned n;
  std::cout << "Eingabe Anzahl Fäden: ";
  std::cin >> n;
  std::vector<std::thread> threads(n);
  
  int id = 0;
  for (auto & t: threads) {
    t = std::thread(hello, ++id);
  }
  std::cout << "was kann man nicht parallelisieren" << std::endl;
  for (auto & t: threads) {
  	t.join();
  }
  return 0;
}
