#include <iostream>
#include <cmath>

int main() {
    double a, b, c, x1, x2;
    std::cout << "Enter ratios of the quadratic equation" << std::endl;
    std::cin >> a >> b >> c;
    if (a == 0 && b == 0 && c != 0) {
        std::cout << "no solutons" << std::endl;
    } else if (a == 0 && b == 0 && c == 0) {
        std::cout << "any numbers" << std::endl;
    } else if (a == 0){
        x1 = -c / b;
        std::cout << "a=0. The only root is x = " << x1;
    }
    else {
        if (b * b - 4 * a * c >= 0) {
            x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            std::cout << "x1 = " << x1 << std::endl;
            std::cout << "x2 = " << x2 << std::endl;
        }
        if (b * b - 4 * a * c < 0) {
            double x11 = -b / (2 * a), x12 = (sqrt(fabs(b * b - 4 * a * c))) / (2 * a);
            std::cout << "Discriminant < 0 - no real solutons" << std::endl
                      << "Roots of a quadratic equation in the field of complex numbers:" << std::endl
                      << "x1 = " << x11 << " + " << x12 << "i"
                      << std::endl
                      << "x2 = " << x11 << " - " << x12 << "i"
                      << std::endl;
        }
    }
    return 0;
}
