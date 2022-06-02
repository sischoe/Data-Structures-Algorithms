// Schreiben Sie ein Programm, das eine natürliche, d.h. vorzeichenlose Zahl n eingibt und die Binärziffern von n in der richtigen Reihenfolge ausgibt (d.h. beginnend mit dem höchstwertigen Bit). Die führenden Nullen dürfen nicht ausgegeben werden.

Einschränkungen: nur der iostream-Standardbibliotheksheader ist erlaubt; die Verwendung von Arrays oder Strings ist nicht erlaubt.
  
  #include <iostream>

int main() {
    unsigned int number;
    std::cout << "Enter a positive integer number:\n";
    std::cin >> number;

    // Methode: absteigende Zweierpotenzen und Subtraktion verwenden

    // Bestimmung der größten Zweierpotenz, die kleiner oder
    // gleich der zu konvertierenden Zahl ist (führende Nullen entfernen).
    unsigned int power;
    for (power = 1; power <= number / 2; power *= 2);
   
    // für alle Zweierpotenzen: Wenn die Subtraktion möglich ist, dann ist diese
    // Zweierpotenz Teil der binären Darstellung von a.
    std::cout << "For " << number << " the binary representation is: ";
    for (; power != 0; power /= 2) {
        if (number >= power) {
            std::cout << "1";
            number -= power;
        } else {
            std::cout << "0";
        }
    }
    std::cout << "\n";

    return 0;
}
