#include <iostream>
#include <vector>
#include <cassert>
#include <mutex>
#include <thread>
#include <random>
#include "barrier.hpp"
#include <sys/time.h>

using mutex = std::mutex;
using guard = std::unique_lock<mutex>;

// instance of Test shared for all threads
class Test{
  unsigned num_threads;
  int value;
  mutex m;  //schlüss
  Barrier barrier; // Klasse 
  bool success;
  int method;
  std::default_random_engine ran {42};
public:
  
  Test(unsigned number_threads, int Method): num_threads(number_threads), value(0), barrier(num_threads), success(false), method(Method){
  };
  
  void inc(){
    guard g(m);
    ++value; // increment
  }

  void dec(){
    guard g(m);
    --value;
  }

  
  bool test(int v){
    guard g(m);
    return value == v;
  }
  
  void single_use(){
    std::uniform_int_distribution<unsigned> uniform {1,10};
    success = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(uniform(ran)));
    inc();
    barrier.arrive_and_wait(); // 
    success = success && test(num_threads);

    std::mutex m;

  }

  void multi_use(){
    std::uniform_int_distribution<unsigned> uniform {0,1};
    success = true;
    for (int i = 0; i<10; ++i){
      std::this_thread::sleep_for(std::chrono::microseconds(uniform(ran)));
      inc();
      barrier.arrive_and_wait();
      success = success && test(num_threads);
      barrier.arrive_and_wait();
      std::this_thread::sleep_for(std::chrono::microseconds(uniform(ran)));
      dec();
      barrier.arrive_and_wait();
      success = success && test(0);
      barrier.arrive_and_wait();
    }
  }
  
void run(){
  if (method == 0)
    single_use();
  else
    multi_use();
}

  void report(){
    std::cout << (success ? "success" : "failed") << std::endl;
    assert(success);
  }
  
};


void drive_test(Test& test){
  test.run();
}

void set_wallclock_timeout(unsigned ms){
  struct itimerval timer;
  
  /* Configure the a timer to expire after wallclock timeout */
  timer.it_value.tv_sec = ms / 1000;
  timer.it_value.tv_usec = ms % 1000 * 1000;
  // no further periodic timeouts after that
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  /* Start a virtual timer. It counts down whenever this process is
   executing. */
  setitimer (ITIMER_REAL, &timer, NULL);
}

int main(){
  unsigned int no_threads;
  std::cout << "enter number threads: " ;
  std::cin >> no_threads;
  int method;
  std::cout << "enter method (0: no reuse, 1: with reuse): " ;
  std::cin >> method;
  Test test(no_threads, method);
  
  set_wallclock_timeout(500);
  
  std::vector<std::thread> threads;
  for (unsigned i = 0; i<no_threads; ++i){
    threads.emplace_back(drive_test, std::ref(test));
  }
  for (unsigned i = 0; i< threads.size(); ++i){
    threads[i].join();
  }
  test.report();
  return 0;
}
