#include <iostream>

int main() {
    unsigned int MAX_UNSIGNED_INT = 4294967295; // 2^32-1
    
    std::cout << "Enter how many fibonacci numbers to print:\n";

    unsigned int number;
    std::cin >> number;

    // try all fibonacci numbers
    unsigned int prev_n = 1;
    unsigned int n = 0;
    bool overflow = false;

    unsigned int i;
    for (i = 0; i < number && !overflow; ++i) {
        std::cout << n << "\n";

        // check for overflow
        overflow = n > MAX_UNSIGNED_INT - prev_n;

        // compute next fibonacci number
        if (!overflow) {
            const unsigned int next_n = n + prev_n;
            prev_n = n;
            n = next_n;
        }
    }

    std::cout << "Printed " << i << " of " << number << " fibonacci numbers\n";
    return 0;
}
