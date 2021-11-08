#include <iostream>
#include <cmath>
#include "quadratic_equations.h"
#include <cassert>
quadraticEquations::quadraticEquations(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;

}

std::pair<double, double> quadraticEquations::solve() {
/*    try {
//        std::cout << "You entered the equation\t" << a << "x^2" << " + " << b << "x +" << c << " = 0" << std::endl;
//        if (a == 0 && b != 0) {
//            throw 1;
//        }
//        if (a == 0 && b == 0 && c != 0) {
//            throw 2;
//        }
//        if (a == 0 && b == 0 && c == 0) {
//            throw 3;
//        } else if (b * b - 4 * a * c > 0) {
//            throw 4;
//        } else if (b * b - 4 * a * c == 0) {
//            throw 5;
//        } else if (b * b - 4 * a * c < 0) {
//            throw 6;
//        }
//    } catch (int e) {
//        e == 1 ? std::cout << -c / b :
//        e == 2 ? std::cout << "There are no solutions" << std::endl << std::endl :
//        e == 3 ? std::cout << "An infinite number of solutions" << std::endl << std::endl :
//        e == 4 ? std::cout << "x1 = " << -b / (2 * a) + sqrt(b * b - 4 * a * c) / (2 * a) << std::endl
//                           << "x2 = " << -b / (2 * a) - sqrt(b * b - 4 * a * c) / (2 * a) << std::endl << std::endl :
//        e == 5 ? std::cout << "x = " << -b / (2 * a) << std::endl << std::endl :
//        std::cout << "There are no real roots" << std::endl << std::endl;
//    }
//    return true;
//} */
    assert(sqrt(b * b - 4 * a * c) >= 0);
    if (a != 0) {
        std::pair<double, double> x;
        x.first = -b / (2 * a) + sqrt(b * b - 4 * a * c) / (2 * a);
        x.second = -b / (2 * a) - sqrt(b * b - 4 * a * c) / (2 * a);
        return x;
    } else {
        std::pair<double, double> x;
        x.first = -c / b;
        x.second = -c / b;
        return x;
    }

}

