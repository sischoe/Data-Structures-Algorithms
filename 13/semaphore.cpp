#include "semaphore.hpp"

class Barrier {

  unsigned int n;
  unsigned int continue;
// Führen Sie einen Zähler ein, der an der Schranke mit dem Anfangswert 0 eingetragen wird.
  
  semaphore s = semaphore(0);
  // (ITIMER_REAL, &timer, NULL);
  // Jeder ankommende Thread erhöht den Zähler um eins.
  // Die Threads warten, bis der Zähler auf n steht und fahren dann fort.

public:
  Barrier(unsigned int N): n(N, matteo(0)){
    if (variable == continue) {
        semaphore::acquire()
        semaphore::release()
    }
    void acquire(){
    guard g(m);
    c.wait(g, [&](){return count != 0;});
    --count;
  }
  }

  void arrive_and_wait(){
  }  

};
