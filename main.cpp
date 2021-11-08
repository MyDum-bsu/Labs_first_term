#include <iostream>
#include "quadratic_equations.h"

int main() {
    quadraticEquations oness(1, 5, 6);
    std::pair<double, double> ones = oness.solve();
    std::cout << "x1 = " << ones.first << std::endl << "x2 = " << ones.second << std::endl;

    quadraticEquations sec(0, 1, 3);
    std::pair<double, double> x = sec.solve();
    std::cout << "x1 = " << x.first << std::endl << "x2 = " << x.second << std::endl;
    quadraticEquations th(0, 0, 3);
    std::pair<double, double> y = th.solve();
    std::cout << "x1 = " << y.first << std::endl << "x2 = " << y.second << std::endl;

    return 0;
}