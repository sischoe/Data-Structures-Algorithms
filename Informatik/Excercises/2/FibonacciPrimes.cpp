/*Fibonacci numbers are the integers in the following sequence: . Each number is the sum of the two previous numbers.

Fibonacci primes are Fibonacci numbers that are also prime numbers. Write a program that asks the user for an integer  and then computes and prints all Fibonacci primes between  and  (including). Print each number on a new line.

Finally, on a new line print the total number of Fibonacci primes found.
*/

#include <iostream>

int main() {
    std::cout << "Enter a positive integer:\n";

    unsigned int m;
    std::cin >> m;

    // try all fibonacci numbers
    unsigned int prev_n = 1;
    unsigned int count = 0;

    for (unsigned int n = 2; n <= m;) {
        
        // test if n is prime
        unsigned int d;
        for (d = 2; (n % d != 0); ++d);

        if (d == n) {
            // found fibonacci prime
            std::cout << n << "\n";
            ++count;
        }

        // compute next fibonacci number
        unsigned int next_n = n + prev_n;
        prev_n = n;
        n = next_n;
    }

    std::cout << "Found " << count << " fibonacci primes\n";
        
    return 0;
}
