#pragma once

class quadraticEquations {
public:
    quadraticEquations(double a, double b, double c);

    std::pair<double, double> solve();

    double solveEquation();

private:
    double a;
    double b;
    double c;
};
