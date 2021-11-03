#pragma once

class quadraticEquations {
public:
    quadraticEquations(double a, double b, double c);

    bool solve();

private:
    double a;
    double b;
    double c;
};
