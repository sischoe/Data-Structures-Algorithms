ETHZürich
Datenstrukturen und Algorithmen 252-0002-00L, 252-0002-AAL
Kurs am D-MATH (CSE) der ETH Zürich, Frühlingssemester 2022, Felix Friedrich

AnkündigungenÜbersichtLehrveranstaltungenAgendaÜbungenMaterialPrüfungenLehrveranstaltungen
Ankündigungen
Datum Nachricht
22.2.2022
Übungseinheiten finden in physischer Präsenz statt.

Wir haben einen zusätzlichen Assistenten für den Kurs für Freitag 14-16h in Anwesenheit (englischsprachige Gruppe in CHN G 22).

Diejenigen, die in eine ONLINE-Gruppe gehen möchten: Wenn Sie in Online-Gruppen keinen freien Platz mehr finden, melden Sie sich bitte in einer beliebigen physischen Gruppe an und gehen Sie dann zur Online-Sitzung. Grund: Ausgleich des Übungsfeedbacks.

11.3.2022
Korrektur eines Copy-and-Paste-Fehlers in den Übungsfolien von Woche 3 (Seite 6)

18.3.2022
verbesserte die Binärzähler-Folien

1.5.2022
verbesserte die Folien zur Computergeometrie

Überblick
Abstrakt
Der Kurs vermittelt die Grundlagen für den Entwurf und die Analyse von Algorithmen. Klassische Probleme vom Sortieren bis hin zu Problemen auf Graphen werden verwendet, um allgemeine Datenstrukturen, Algorithmen und Paradigmen des Algorithmusdesigns zu diskutieren. Der Kurs umfasst auch eine Einführung in die parallele und nebenläufige Programmierung und das Programmiermodell von C++ wird ausführlich behandelt. Alle erforderlichen mathematischen Werkzeuge über dem Abiturniveau werden behandelt, einschließlich einer grundlegenden Einführung in die Graphentheorie. Die Übungen werden in Code-Expert durchgeführt, einem Online-IDE- und Übungsverwaltungssystem.

Lernziel
Ein Verständnis für die Analyse und das Design grundlegender und gängiger Algorithmen und Datenstrukturen. Vertiefter Einblick in ein modernes Programmiermodell anhand der Programmiersprache C++. Kenntnisse über Chancen, Probleme und Grenzen paralleler und nebenläufiger Programmierung.

Voraussetzungen
Vorlesungsreihe 252-0856 Informatik oder gleichwertige Kenntnisse in der Programmierung mit C++.

Klassen
Vorlesungen Montag 10:15 - 12:00 Uhr HG G 3 Stream
Freitag 08:15 - 10:00 HG G 3 Stream
Die (deutschsprachigen) Vorlesungen werden aufgezeichnet. Videos werden in der Agenda unten zur Verfügung gestellt.

Agenda
Das ist ein Plan. Kein Plan überlebt den Kontakt mit der Realität. Wir werden das Vorlesungsmaterial vor den Vorlesungen ständig aktualisieren.

Nummer Datum Thema, Videos und Aufzeichnungen Vorlesungsmaterial Übungen
1 Mo 21.02. Überblick, Algorithmen und Datenstrukturen, Effizienz von Algorithmen, Random-Access-Maschinenmodell, Funktionswachstum, Asymptotik [Cormen et al, Kap. 2.2,3,4.2-4.4 | Ottmann/Widmayer, Kap. 1.1]
Vorlesungsaufzeichnung: Vorlesungsvideo
Alternative Videos (2021, Englisch): Organisation , Einführung , Asymptotik Organisation: [de] [en]
Folien 1: [de] [en]
Handout 1: [de] [en]
Codebeispiel: Laufzeiten sortieren Einschreibung / Enrollment
Übung 01: Big-O-Notation, asymptotisches Wachstum, Theta(g) der Menge, Laufzeiten von Codeschnipseln, einige Beweise, Präfixsumme in 2D
2 Fr 25.02. Korrektheit und Effizienz von Algorithmen am Beispiel: altägyptische Multiplikation, schnelle ganzzahlige Multiplikation, [Ottman/Widmayer, Kap. 1.2.3] Algorithmusentwurf – Maximum-Subarray-Problem [Ottman/Widmayer, Kap. 1.3], Teile und herrsche [Ottman/Widmayer, Kap. 1.2.2. S.9; Cormen et al., Kap. 4-4.1]
Vorlesungsaufzeichnung: Vorlesungsvideo
Alternative Videos (2021, Englisch): EgyptianMultiplication , KaratsubaOfman , Karatsuba:Appendix(Runtime) , Maximum-Subarray Slides 2: [de] [en]
Handout 2: [de] [en] Folie 01: [de] [en]
3 Mo 28.02. C++ Advanced (I): RAII-Vektoren, Zeiger und Iteratoren, Bereich für, Schlüsselwort auto, eine Klasse für Vektoren, Subscript-Operator, Bewegungskonstruktion und Fünferregel, Iteratoren
Vorlesungsaufzeichnung: Vorlesungsvideo
Alternative Videos (2021, Englisch): ToolsAndMemoryManagement , EfficientMemoryManagement Slides 3: [de] [en]
Handout 3: [de] [en] Übung 02: Verbesserung der Sortierung, Vektorvorlage, verschachtelte Vektoren, Schiebefenster, Beweise durch Induktion
4 Fr 04.03. C++ erweiterte (II) Vorlagen. Vorlagen von Klassen, Funktionsvorlagen, Konzepte, Spezialisierung
Suche und Selektion Lineare Suche, Binäre Suche, (Interpolationssuche,) Untere Schranken [Ottman/Widmayer, Kap. 3.2, Cormen et al., Kap. 2: Aufgaben 2.1-3,2.2-3,2.3-5]
Vorlesungsaufzeichnung: Vorlesungsvideo
Alternative Videos (2021, Englisch, Konzepte und Spezialisierung nicht abgedeckt): Vorlagen , Durchsuchen von Folien 4: [de] [en]
Handout 4: [de] [en] Folien 02: [de] [en]
5 Mo 07.03. Suche und Auswahl Das Auswahlproblem, randomisierte Auswahl, lineare Worst-Case-Auswahl [Ottman/Widmayer, Kap. 3.1, Cormen et al., Kap. 9] Algorithmus von Blum, Floyd, Pratt, Rivest und Tarjan (Median der Mediane)
Sortieren naiver Sortieralgorithmen [Ottman/Widmayer, Kap. 2.1, Cormen et al., Kap. 2.1, 2.2, Aufgabe 2.2-2, Aufgabe 2-2],
Vorlesungsaufzeichnung: Vorlesungsvideo
Alternative Videos: QuickSelect , Blum , NaiveSorting Slides 5:[de] [en]
Handout 5:[de] [en] Übung 03: Rekursive Funktionsanalyse, Eier werfen, Die Master-Methode, Quick-Select, Mergesort
6 Fr 11.03. Sortieren Mergesort [Ottman/Widmayer, Kap. 2.4, Cormen et al., Kap. 2.3], Quicksort [Ottmann/Widmayer, Kap. 2.2, Cormen et al., Kap. 7]
Vorlesungsaufzeichnung: Vorlesungsvideo
Alternative Videos: Sortierung zusammenführen und Schnellsortierung , Mast
