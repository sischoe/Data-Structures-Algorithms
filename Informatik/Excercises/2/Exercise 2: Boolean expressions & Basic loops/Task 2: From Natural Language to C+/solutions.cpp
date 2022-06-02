// Fill out each function with the appropriate questions. 

bool task1(unsigned int a, unsigned int b) { 
  // a ist größer als b und die Differenz zwischen a und b ist kleiner als 15.
  return a > b && a - b < 15; 
}


bool task2(unsigned int a) { 
  // a ist eine gerade natürliche Zahl größer als 3.
  return a % 2 == 0 && a > 3;
}


bool task3(unsigned int a, unsigned int b, unsigned int c) { 
  // a ist höchstens 5 mal größer als b (kann aber auch kleiner als b sein) 
  // und mindestens 5 mal größer als c.
  return a <= b * 5 && a >= 5 * c; 
}


bool task4(unsigned int a, unsigned int b, unsigned int c) { 
  // Either a and b are both false or c is true, but not both.
  // Entweder sind a und b beide falsch oder c ist wahr, aber nicht beides.
  return (!a && !b) != c; 
}


bool task5(unsigned int a, unsigned int b) { 
  // a  is false and b is zero.
  return !a && b == 0; 
}
