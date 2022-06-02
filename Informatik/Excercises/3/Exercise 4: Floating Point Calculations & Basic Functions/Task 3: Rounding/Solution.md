# Solution

By the C++ standard, converting a floating point number to `c++|int` cuts off the fractional part. Then, we compute the difference between the original number and its truncation. Under the IEEE standard 754, this difference has less significant binary digits than the original number, but those which it still has, are the same. Thus, normalizing this number works by simply adjusting the exponent and filling up the emerging digits with $0$. Therefore the truncated number is exactly representable as a `c++|double` value.

Now we can exactly test whether the difference is less than $0.5$ (in which case we return the truncation), or at least $0.5$ (in which case we return the next integer, going away from zero).


## Lösung

Nach dem C++-Standard wird bei der Konvertierung einer Fließkommazahl in `c++|int` der Nachkommateil abgeschnitten. Anschließend wird die Differenz zwischen der ursprünglichen Zahl und ihrer Abschneidung berechnet. Nach dem IEEE-Standard 754 hat diese Differenz weniger signifikante Binärziffern als die ursprüngliche Zahl, aber die, die sie noch hat, sind die gleichen. Die Normalisierung dieser Zahl erfolgt also durch einfaches Anpassen des Exponenten und Auffüllen der entstehenden Ziffern mit $0$. Daher ist die abgeschnittene Zahl genau als ein `c++|double`-Wert darstellbar.

Jetzt können wir genau testen, ob die Differenz kleiner als $0.5$ ist (in diesem Fall geben wir die abgeschnittene Zahl zurück), oder mindestens $0.5$ (in diesem Fall geben wir die nächste ganze Zahl zurück, die von Null weggeht).

