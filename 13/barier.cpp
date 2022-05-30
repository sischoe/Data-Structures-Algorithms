#include "semaphore.hpp"

class Barrier {

  unsigned int n;
  unsigned int matteo;
  unsigned int counter; // Führen Sie einen Zähler ein, der an der Schranke mit dem Anfangswert 0 eingetragen wird.
  
  settimer s = settimer(0);
  // (ITIMER_REAL, &timer, NULL);
  // Jeder ankommende Thread erhöht den Zähler um eins.
  // Die Threads warten, bis der Zähler auf n steht und fahren dann fort.

public:
  Barrier(unsigned int N): n(N){
    semaphore::acquire();
    semaphore::release();
  }

  void arrive_and_wait(){
  }  

};
