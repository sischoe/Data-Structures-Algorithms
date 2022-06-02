// Programm zur Berechnung des Ersatzwiderstands
// einer Verdrahtung von vier Widerständen berechnet. R1,R2,R3 und R4
// wobei R1 und R2, R3 und R4 in Reihe verdrahtet sind
// was zu R12 und R23 führt, die parallel verdrahtet sind


#include <iostream>

int main() {
    // input
    std::cout << "Bitte eingeben R1\n";
    int R1;
    std::cin >> R1;
    
    std::cout << "Bitte eingeben R2\n";
    int R2;
    std::cin >> R2;
    
    std::cout << "Bitte eingeben R3\n";
    int R3;
    std::cin >> R3;
    
    std::cout << "Bitte eingeben R4\n";
    int R4;
    std::cin >> R4;

    // computation
    const int R12 = R1 + R2;
    const int R34 = R3 + R4;
    const int R = (R12 * R34 + (R12 + R34) / 2) / (R12 + R34);

    // output
    std::cout << "Äquivalenter Widerstand: " << R << "\n";
    return 0;
}
