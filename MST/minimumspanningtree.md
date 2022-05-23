# Minimale Spannbäume
Die minimalen Spannbäume gehören zur Kategorie der Graphenprobleme. Ein
minimaler Spannbaum, ist ein Baum, dessen Summe der Kantengewichte
minimal ist. Doch was ist ein Baum? Als Baum bezeichnet man in der
Graphentheorie einen Graphen mit N Knoten, welcher durch genau
N-1 Kanten so miteinander verbunden ist, dass zwischen zwei
Knoten genau einen Weg gibt.

Der blaue Graph ist ein Baum. Der grüne Graph ist kein Baum, da er mehr als :math:`N-1` Kanten hat und deswegen auch einen Zyklus (Länge 4) enthält. Der weisse Graph ist ebenfalls kein Baum, da er nicht die richtige Anzahl Kanten hat und in mehrere Subgraphen aufgeteilt ist, d.h. es gibt nicht zwichen jeden zwei Punkten einen Weg.

Für einen Graphen gibt es oft mehrere verschiedene Arten wie ein Spannbaum gewählt werden kann. Uns interessiert allerdings vorallem, wie man die Summe der Kantengewichte des Baumes minimieren, respektive maximieren kann. Dieses Problem ist unter dem Namen “minimal spannender Baum” oder kurz “MST” (minimal spanning tree) bekannt. Für das MST Problem gibt es zwei bekannte Lösungsideen, die Algorithmen von Kruskal und Prim. Es kann auch sein, dass es mehrere minimale Spannbäume gibt.

[png](https://i.imgur.com/Kn4u4mK.png)

# [Lösungsansatz Kruskal](https://i.imgur.com/5vwi3X9.png)
Wir betrachten in unserem Graphen die Kante mit dem kleinsten Gewicht. Diese Kante ist sicher Teil eines gültigen Spannbaumes, sofern sie keinen Zyklus formt (die Baum-Bedingung verletzt). Stellen wir uns vor, wir haben unseren minimalen Spannbaum gefunden und wir teilen den Spannbaum in zwei Komponenten (blau, grün) auf, wobei die kleinste Kante genau zwischen den Beiden Komponenten ist. Um den gesamten Spannbaum zu konstruieren, müssen wir jetzt genau eine Kante einfügen, welche die beiden Komponenten wieder verbinden. Dazu kommen alle Kanten in Frage, welche den Startknoten im blauen und den Endknoten im grünen Bereich haben (gestrichelte Kanten). Weil wir den minimalen Spannbaum möchten, ist dies genau die kleinste Kante (alle anderen Kanten haben ein grösseres Kantengewicht), welche wir am Anfang betrachtet haben (gefüllte Kante).

Immer wenn wir eine Kante auswählen und hinzufügen, können wir uns dies auch als Verschmelzung der beiden Knoten vorstellen, welche wiederum einen Knoten bilden. Bei diesem Prozess erniedrigen wir die Anzahl Knoten immer um genau eins. Wir erhalten somit einen neuen Graphen und können das gleiche Verfahren erneut anwenden, bis nur noch ein einziger Knoten übrig bleibt. Die Abfolge der ausgewählten Kanten, welche zur “Verschmelzung” geführt haben bilden einen MST.

Die kleinste Kante (blau) befindet sich zwischen 1 und 7, deswegen ist sie Teil unseres MST. Wir können uns dies auch als “Verschmelzung” der Knoten vorstellen.

In Wirklichkeit “verschmelzen” wir die Knoten nicht, sondern unterteilen sie in verschiedene Subgraphen. Wir können dann mithilfe von Union Find effizient entscheiden, ob sich zwei Knoten im selben Subgraphen befinden (bereits “verschmelzt” worden sind) und zwei Subgraphen miteinander verbinden.

Vorgehen
Sortiere alle Kanten aufsteigend nach ihrem Kantengewicht
Nimm die kleinste Kante, bis keine Kanten mehr vorhanden sind
Falls die beiden Endpunkte der Kante nicht im gleichen Subgraphen liegen:
Kante dem minimalen Spannbaum hinzufügen
Subgraphen miteinander verbinden.
Als erstes sortieren wir alle Kanten nach ihrem Kantengewicht. In den SOI Aufgaben ist der Graph oft in verschiedenen “Formaten” gegeben, es kann also gut sein, dass du den Graphen in eine andere From bringen must. Für den Algorithmus von Kruskal brauchen wir alle Kanten in einem Vektor. Dabei lohnt es sich folgende Struktur zu verwenden:


```// gewicht, von, zu
vector<pair<int,pair<int,int> > > edges;


```

Denn nun können wir die eingebaute Sortierfunktion con C++ brauchen um alle Kanten nach ihrem Gewicht zu sortieren. Dabei ist die Kante mit dem kleinsten Gewicht (kann auch negativ sein) zuvorderst im Vektor.

```sort(edges.begin(), edges.end());```

Um zu entscheiden ob zwei Knoten im selben Subgraphen sind (bereits “verschmelzt” wurden), brauchen wir Union Find. Dazu gibt es ein separates Skript. Nun betrachten wir alle Kanten für die Konstruktion unseres MST’s.

```for(int i=0; i<(int)edges.size();i++){
        int from = edges[i].second.first;
        int to = edges[i].second.second;
        int w = edges[i].first;
        ...
    }```
    
    Wenn zwei Kanten im selben Subgraphen sind, können wir sie überspringen.

```if(find(to) == find(from)){
    continue;
}```


Ansonsten ist die Kante teil des minimalen Spannbaumes. Wir fügen ihr Kantengewicht dem Gesamtgewicht hinzu und verbinden die beiden Subgraphen.
```unite(to, from);
weight += w;
```

Möchten wir statt eines minimalen Spannbaumes einen Spannbaum mit
maximalen Kantengewicht finden, können wir einfach alle Kanten negieren
(mit -1 multiplizieren) und den gleichen Algorithus verwenden.

# Implementierung

