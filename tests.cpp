#include "gtest/gtest.h"
#include "quadratic_equations.h"

TEST(solve, When_TwoSolutions) {
    quadraticEquations noka(-1, 6, 7);
    std::pair<double, double> x;
    x.first = 7;
    x.second = -1;
    std::pair<double, double> xV;
    xV.first = x.second;
    xV.second = x.first;
    ASSERT_TRUE((noka.solve() == x) || (noka.solve() == xV));
}

TEST(solve, When_OneSolutions) {
    quadraticEquations noka(0, 7, 7);
    std::pair<double, double> x;
    x.first = -1;
    x.second = -1;
    std::pair<double, double> xV;
    xV.first = x.second;
    xV.second = x.first;
    ASSERT_TRUE((noka.solve() == x) || (noka.solve() == xV));
}