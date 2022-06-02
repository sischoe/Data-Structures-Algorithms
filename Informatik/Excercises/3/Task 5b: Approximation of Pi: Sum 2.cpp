#include <iostream>

int main() {
    // input n
    unsigned int m;
    std::cin >> m;

    // computation of sum 2

    // initialize auxiliary variables for first term of sum
    double numer = 2.0; // numerator i-th term
    double denom = 1.0; // denominator i-th term

    // pi: value after term i (i=0 initially, then i=1,2,...,n-1)
    double pi2 = 2.0;
    for (unsigned int j = 1; j < m; ++j) {
        numer *= j;
        denom *= 2 * j + 1;
        pi2 += numer / denom;
    }

    // output
    std::cout << "sum 2: " << pi2 << "\n";

    return 0;
}

// Sum 2 gives a more precise approximation of pi than sum 1 with the same
// number of terms. However, it is important to decide at which point to stop
// the computation: the terms in numerator and denominator quickly grow beyond
// the capacity of type double, resulting in "not a number" result.
