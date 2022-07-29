# Solution

1.  ✓ `a = b = 5` is a valid expression. It is parenthesized as `a = (b = 5)`.
    The expression is a l-value (memory location of `a`) and its value is 5.
    
2.  × `1 = a` is not a valid expression. `1` is an r-value and cannot
    stand at the left side of an assignment.

3.  ✓ `++a + b++` is a valid expression. It is parenthesized as
  `(++a) + (b++)`. The expression is an addition of two variables, and
  therefore an r-value. It evaluates to `(a + 1) + b`, as calculated from
  the initial values of  `a` and `b`.

4.  × `a + b = c + d` is not a valid expression. Left hand side is an r-value.

5.  × `a = 2 b` is not a valid expression. The right hand side is
    syntactically incorrect (missing operator).
    
  

# Lösung

1. ✓ „a = b = 5“ ist ein gültiger Ausdruck. Es wird als "a = (b = 5)" eingeklammert.
     Der Ausdruck ist ein L-Wert (Speicherort von `a`) und sein Wert ist 5.
    
2. × `1 = a` ist kein gültiger Ausdruck. "1" ist ein r-Wert und kann es nicht
     auf der linken Seite einer Aufgabe stehen.

3. ✓ `++a + b++` ist ein gültiger Ausdruck. Es ist als eingeklammert
   `(++a) + (b++)`. Der Ausdruck ist eine Addition von zwei Variablen und
   daher ein r-Wert. Es ergibt `(a + 1) + b`, berechnet aus
   die Anfangswerte von "a" und "b".

4. × „a + b = c + d“ ist kein gültiger Ausdruck. Die linke Seite ist ein r-Wert.

5. × „a = 2 b“ ist kein gültiger Ausdruck. Die rechte Seite ist
     syntaktisch falsch (fehlender Operator).

// Estheryu991/Data-Structures-Algorithms
