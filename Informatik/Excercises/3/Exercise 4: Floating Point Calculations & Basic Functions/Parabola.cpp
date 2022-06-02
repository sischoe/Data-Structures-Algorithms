#include <iostream>

double abs(double value) {
    if (value < 0.0) {
        return -value;
    } else {
        return value;
    }
}

int main() {
    double abs_err = 1e-4;

    //std::cout << "Enter x coordinate of point P: ";
    double x;
    std::cin >> x;

    //std::cout << "Enter y coordinate of point P: ";
    double y;
    std::cin >> y;

    double a = 0.9;
    double b = 1.3;
    double c = -0.7;
    double res = a * x * x + b * x + c;

    // is point within absolute error tolerance?
    if (abs(res - y) < abs_err) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    
    return 0;
}
