#include <iostream>
#include "loop.h"

// Fill out the file with the required answers


/*

  Subtask 1: Describe the output of the program as a function of its input n.

  The program computes x = 2^n.

*/

/*

  Subtask 2: For which values of n do you expect a correct output x? Explain why.

  The critical point is the value range of `unsigned`-typed x, since x
  increases exponentially. On 32-bit systems for example a common maximum 
  value for `unsigned` is given by (2^32)-1, resulting in invalid results 
  for inputs of n >= 32. The range of inputs producing correct \
  outputs would then be n in {0,  ..., 31}.

*/


/*

  Subtask 3: Show that this program terminates for all values of n found in (2).
  
  For n = 0, the program terminates after not entering the `if`-block.  
  For n in {1, ..., 31}, `k` is strictly monotonic increasing from start 
  value 0 and is increased by 1 in each iteration, eventually fulfilling 
  `k = n` and setting the termination condition. 
  This is independent of the value of `x`.
  
*/

/*
  Subtask 4: Provide a more elegant implementation of this function using 
  another type of loop.
*/

void loop(){
  
  unsigned int n;
  std::cin >> n;
  
  unsigned int x = 1;
  for (unsigned int k = 0; k < n; ++k) {
     x *= 2;
  }
  std::cout << x << std::endl;
  
}

