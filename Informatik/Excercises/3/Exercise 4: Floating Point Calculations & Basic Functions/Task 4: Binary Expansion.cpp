#include <iostream>

// PRE: keine
// POST: Rückgabe 1, wenn x >= 1, sonst 0.
int calculate_b(double x) {
    int b;
    if (x >= 1) {
        b = 1;
    } else {
        b = 0;
    }
    return b;
}

int main() {
    std::cerr << "Please enter decimal number x in the range 0<=x<2:\n";
    
    double x;
    std::cin >> x;
    
    if (x < 0.0 || x >= 2.0) {
        std::cout << "Input out of bounds\n";
        return 1;
    }
    
    int b = calculate_b(x);
    std::cout << b << ".";
    
    for (int i = 1; i < 16; ++i) {
        x -= b;
        x *= 2;
        b = calculate_b(x);
        std::cout << b;
    }
    
    std::cout << "\n";
    return 0;
}
