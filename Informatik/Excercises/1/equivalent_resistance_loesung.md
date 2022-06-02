# Lösung

Der Schlüssel zur Lösung sind die Regeln für serielle und parallele Schaltungen:

(1) $R_{12} = R_1 + R_2$

(2) $R_{34} = R_3 + R_4$

(3) $1/R_{1234} = 1/R_{12} + 1/R_{34} \quad R_{1234} = (R_{12}\cdot R_{34}) / (R_{12} + R_{34}),$

und die Regel für die arithmetische Rundung (unter Verwendung des Symbols $\div$ für die ganzzahlige Division)

$\lfloor a/b+1/2 \rfloor = (a + b \div 2) \div b.$

$\qquad$

**Anmerkung:** Die Regel für die arithmetische Rundung kann wie folgt bewiesen werden. Dies ist
in deiner Lösung nicht erwartet, aber eine interessante Hintergrundinformation:

Es gilt, dass

$\qquad a \div b = \max\{n\in\Bbb{N}: b\cdot n \leq a\}$.

$\qquad$

Daraus folgt:

$\qquad (a + b \div 2) \div b = \max\{n\in\Bbb{N}: b\cdot n \leq a + b \div 2\}$

$$$qquad = \max\{n\in\Bbb{N}: b\cdot n \leq a + b / 2\}, \mbox{wenn $b$ gerade ist}$$

$$\qquad = \max\{n\in\Bbb{N}: n \leq a/b + 1/2\}, \mbox{wenn $b$ gerade ist}$$

$$\qquad = \max\{n\in\Bbb{N}: b\cdot n \leq a + (b-1) / 2\}, \mbox{wenn $b$ ungerade ist}$$

$$\qquad = \max\{n\in\Bbb{N}: n \leq a/b + 1/2 - 1/(2b)\}, \mbox{wenn $b$ ungerade ist}$$

$$\qquad \overset{!}{=} \max\{n\in\Bbb{N}: n \leq a/b + 1/2\}, \mbox{wenn $b$ ungerade ist}$$

$\qquad$

Beweis von $\overset{!}{=}$:

$\qquad n \leq a/b + 1/2$

$\qquad \Leftrightarrow b\cdot n \leq a + b/2$

$\qquad \Rightarrow b\cdot n \leq a + (b-1)/2,\qquad \mbox{da $b$ ungerade ist und lhs ganzzahlig ist.}$$

$\qquad \Rechtspfeil n \leq a/b + 2/2 - 1/(2b),$

$\qquad n > a/b + 1/2 - 1/(2b),$

$$\qquad \Leftrightarrow b\cdot n > a + (b-1)/2,\qquad \mbox{da $b$ ungerade und lhs ganzzahlig ist.}$$

$$\qquad \Rightarrow b\cdot n > a + b/2,\qquad \mbox{da $b$ ungerade ist und lhs eine ganze Zahl ist.}$$

$\qquad \Leftrightarrow n > a/b + 1/2$
