#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: describe what the code snippet computes

  The snippet repeatedly computes the sum of two user provided integer numbers.

*/

/*

  Subtask 2: decide wwhich of the other two kind of loops would fit better

  
  (Note that for this sub task, there is no exact answer.) 
  The presented `while` version is inelegant because it uses `break`. 
  While this can be omitted, the `do-while` version is natural here, 
  because it directly reflects the fact that the body runs at least once. 
  The `for` version is again concise, but unreadable because the condition 
  and “increment” expression are unusual. Moreover, the termination condition 
  is redundantly evaluated at the beginning.


*/


/*
  Subtask 3: update the function below by rewriting the snippet into the 
  loop you specified in (2)
*/

void loop(){

  int again;
  do {
      int i1, i2;
      std::cin >> i1 >> i2;
      std::cout << i1 + i2 << "\n";

      std::cout << "Again? (0/1)\n";
      std::cin >> again;
  } while (again != 0);

  
}
