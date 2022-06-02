#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: describe what the code snippet computes

  <Insert your answer here, within the comment block>

*/

/*

  Subtask 2: decide wwhich of the other two kind of loops would fit better

  <Insert your answer here, within the comment block>

*/


/*
  Subtask 3: update the function below by rewriting the snippet into the 
  loop you specified in (2)
*/

void loop(){
  
  unsigned int n;
  std::cin >> n;
  unsigned int f = 1;
  if (n != 0) {
    do {
      f = f * n;
      --n;
    } while (n > 0);
  }
  std::cout << f << std::endl;
  std::cout << n << std:endl;  
}



