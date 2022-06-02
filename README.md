# DataStructures-Algorithm_cpp

Die Details der Vorlesung finden Sie [hier](https://lec.inf.ethz.ch/DA/2022/) 

Für Informatik, klicke [hier](https://lec.inf.ethz.ch/itet/informatik1/2022/): 

Der Kurs vermittelt die Grundlagen für den Entwurf und die Analyse von Algorithmen. Anhand klassischer Probleme, die vom Sortieren bis hin zu Problemen auf Graphen reichen, werden gängige Datenstrukturen, Algorithmen und Paradigmen für den Algorithmenentwurf diskutiert. Der Kurs umfasst auch eine Einführung in die parallele und nebenläufige Programmierung und das Programmiermodell von C++ wird eingehend diskutiert. Alle erforderlichen mathematischen Werkzeuge oberhalb des Highschool-Niveaus werden behandelt, einschließlich einer grundlegenden Einführung in die Graphentheorie. Die Übungen werden in Code-Expert durchgeführt, einem Online-IDE und Übungsmanagementsystem.

# Lernziel
Verständnis für die Analyse und den Entwurf grundlegender und gängiger Algorithmen und Datenstrukturen. Vertiefter Einblick in ein modernes Programmiermodell anhand der Programmiersprache C++. Kenntnisse über Chancen, Probleme und Grenzen der parallelen und nebenläufigen Programmierung.

# Voraussetzungen
Ringvorlesung 252-0856 Informatik oder gleichwertige Kenntnisse in der Programmierung mit C++.


## Übung 1:

Große O-Notation
 
Asymptotisches Wachstum
 
Das Set Theta(g)

Laufzeiten von Codeschnipseln

Einige Beweise

Präfix Summe in 2D

## Übung 2
Verbesserung der Sortierung

Vektor-Vorlage

Verschachtelte Vektoren

Schiebefenster

Beweise durch Induktion

## Übung 3
 
Rekursive Funktionsanalyse

Eier werfen

Die Master-Methode

Schnellauswahl

Zusammenführen, sortieren

## Übung 4
 
Vergleich von Sortieralgorithmen
 
Stall- und In-Situ-Sortierung

Amortisierte Analyse: Dynamisches Array

Doppelende Warteschlange

## Übung 5
 
Divisionsmethode und Zweierpotenzen

Kuckucks-Hashing

Adressierung öffnen

Finden eines Sub-Arrays (Rabin-Karp)

## Übung 6

Binäre Suchbäume, AVL-Bäume und Heaps

AVL-Bäume

Verketten von Haufen

Haufen: k kleinste Elemente

Zuordnen/Filtern/Reduzieren

## Übung 7

Quadtrees: Bildsegmentierung
 
DP: Maximale Summe einer steigenden Teilfolge (DP)

DP: Stückweise konstante Approximation

DP: Mars-Mission

## Übung 8

Autokorrektur

Palindrome aufzählen

DP: Eier werfen

Reisender Verkäufer

## Übung 9

Programmierübung: Huffman-Code

Konvexe Hülle

Nächstgelegenes Punktpaar

## Übung 10

Erstaunliche Labyrinthe I (BFS)

Diagrammeigenschaften

Topologische Sortierung und verbundene Komponenten

Dijkstra von Hand

## Übung 11

Zentralität der Nähe

Union-Find

Der vorbereitende Student (MST Kruskal)

Der reisende Student (TSP 2-ca.)

Minimum Spanning Tree – Theorie

## Übung 12

Manueller maximaler Durchfluss

Anwenden des maximalen Durchflusses

Min-Cut-Probleme

Beschleunigung, Amdahl, Gustavson

Summe eines Vektors

Sortierung

## Übung 13

Philosophen speisen

Rennbedingungen

Barriere

Brücke

# Code Beispiel: 

Sandbox
 
Sandbox Task For Your Experiments

Lecture01: Sorting Runtimes

Sorting Runtimes (Wallclock Time)

Sorting Runtimes (CPU Time)

Lecture02: algorithm examples

maximum subarray problem

Karatsuba

Lecture03: tools, rule of three/five, iterators
Open
useful tools
rule of three
iterators
rule of five
vector movement
Lecture04: templates
Open
classes (pair)
functions
containers (findmin)
fancy (apply functions)
self-made shared pointer
smart pointers
type traits
type inference (C++17 vs C++14)
simple template metaprogramming
Exercise class 02: Subarray Sum Problem
Open
Subarray Sum Problem
Lecture 06: sorting
Open
Improving Sorting Reprise
Exercise class 04: Dynamically sized array
Open
Dynamically sized array
Lecture 10: Functors and Lambdas
Open
Filters
Sorting Comparators
Simple Lambda Examples
Sums and For-Each
Captures
Functional
Function smoothing
Exercise class 06: Binary Trees
Open
Binary Tree
Augmenting a Binary Search Tree
Lecture 13: DP
Open
Fibonacci
Rod-Cutting
Rabbits
Exercise class 07: Dynamic Programming
Open
Longest Ascending Sequence
Exercise class 08/09: DP
Open
Optimal Search Trees
Lecture 17: Computational Geometry
Open
Intersect Two Lines
Check if Segments Intersect
Enumerate all Segment Intersections
Exercise class 10: Graphs and Shortest Paths
Open
BFS on a Tree
Lazy Deletion
Exercise class 11: Minimum Spanning Trees
Open
Union Find Experiments
code examples PP I
Open
Concurrent Hello World
Parallel Fibonacci (with Threads)
Parallel Fibonacci (with Futures)
Parallel Sum
Parallel Scalar Product
Pow8 on a vector
code examples PP II
Open
Bank Account Unsynchronized
Bank Account Synchronized (I)
Counter
Bank Account Synchronized (II) and Deadlocks
Producer Consumer Pattern
code examples PP III
Open
Self-made Future
Using Futures
Spinlock
Lock free stack 



## Uebung 1: 
  Big O Notation
 
Asymptotic Growth
 
The Set Theta(g)

Code Snippets Running Times

Some Proofs

Prefix Sum in 2D

## Uebung 2
Improving Sorting

Vector Template

Nested Vectors

Sliding Window

Proofs by Induction

## Exercise 3
 
Recursive Function Analysis

Throwing Eggs

The Master Method

Quick Select

Mergesort

## Exercise 4
 
Comparing Sorting Algorithms
 
Stable and In-Situ Sorting

Amortized Analysis: Dynamic Array

Double Ended Queue

## Exercise 5
 
Division Method and Powers of Two

Cuckoo hashing

Open Addressing

Finding a Sub-Array (Rabin-Karp)

## Exercise 6

Binary Search Trees, AVL Trees and Heaps

AVL Trees

Concatenating Heaps

Heaps: k smallest elements

Map/Filter/Reduce

## Exercise 7

Quadtrees: Image Segmentation
 
DP: Maximum sum of an increasing subsequence (DP)

DP: Piecewise Constant Approximation

DP: Mars mission

## Exercise 8

Autocorrect

Enumerating Palindromes

DP: Throwing Eggs

Traveling salesman

## Exercise 9

Programming exercise: Huffman Code

Convex Hull

Closest Point Pair

## Exercise 10

Amazing Mazes I (BFS)

Graph Properties

Topological sorting and connected components

Dijkstra by Hand

## Exercise 11

Closeness centrality

Union-Find

The Preparing Student (MST Kruskal)

The Travelling Student (TSP 2-Approx)

Minimum Spanning Tree -- Theory

## Exercise 12

Manual Maximum Flow

Applying Maximum Flow

Min-Cut Problems

Speedup, Amdahl, Gustavson

Sum of a vector

Sorting

## Exercise 13

Dining philosophers

Race Conditions

Barrier

Bridge
