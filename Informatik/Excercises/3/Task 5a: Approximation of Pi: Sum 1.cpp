#include <iostream>

int main() {
    // input m: 
    // \frac{\pi}{4} = \sum\limits_{0\le n}{\frac{(-1)^n}{2n+1}} = 1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \ldots
    unsigned int m;
    std::cin >> m;

    // computation of sum 1
    double pi1 = 0.0;
    for (unsigned int n = 1; n < 2 * m; n += 2) {
        if (n % 4 == 1) {
            pi1 += 4.0 / n;
        } else {
            pi1 -= 4.0 / n;
        }
    }

    // output
    std::cout << "sum 1: " << pi1 << "\n";

    return 0;
}
