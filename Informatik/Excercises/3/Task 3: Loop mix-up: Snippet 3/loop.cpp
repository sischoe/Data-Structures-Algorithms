#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: describe what the code snippet computes

  The snippet outputs 1 if the input number is prime or equal to 0 or 1, 0 otherwise.

*/

/*

  Subtask 2: decide wwhich of the other two kind of loops would fit better

  ((Note that for this sub task, there is no exact answer.) 
  The presented `while` version is inelegant because it uses `break`. 
  A `while`  version is natural here, 
  because it directly reflects the fact that the body may not runs, and capture
  the exit condition.

*/


/*
  Subtask 3: update the function below by rewriting the snippet into the 
  loop you specified in (2)
*/

void loop(){
  
  unsigned int n;
  std::cin >> n;
  int ok = 1;
  unsigned int i=2;
  while (ok && i <= n/2){
    ok = (n % i) != 0;
    i++;
  }
  std::cout << ok << std::endl;
  
}

