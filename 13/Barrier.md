 Synchronisationskonstrukt mit der folgenden Semantik:

Jeder Thread, der eine Barriere im Code erreicht, muss warten, bis alle Threads die Barriere erreicht haben.
Sobald die Threads die Barriere erreicht haben, dürfen alle wartenden Threads ihre Ausführung fortsetzen.

Wir unterscheiden Schranken nach ihrer Wiederverwendbarkeit. Es ist einfacher, eine Barriere zu implementieren, die nur einmal verwendet wird, als eine Barriere mit Wiederverwendbarkeit zu implementieren.

Bei dieser Aufgabe erhalten Sie die Hälfte der Punkte für eine korrekt implementierte Barriere, die nur einmal verwendet werden kann. Sie erhalten die volle Punktzahl, wenn eine Barriere mehrfach verwendet werden kann (z. B. in einer Schleife).

Anwendungsbeispiel für eine wiederverwendbare Barriere:

```barrier barrier(number_threads); // usable by all threads```

## Aufgabe
Implementiere eine Barriere mit der Schnittstelle:

Jeder Thread, der eine Barriere im Code erreicht, muss warten, bis alle Threads die Barriere erreicht haben.

```class Barrier {
public:
  Barrier(unsigned n); // constructor
  void arrive_and_wait();
}```

nur auf der Grundlage der angegebenen Klasse semaphore in der Datei semaphore.hpp, die Operationen enthält

