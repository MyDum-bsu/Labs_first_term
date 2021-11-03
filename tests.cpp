#include "gtest/gtest.h"
#include "quadratic_equations.h"

TEST(solve, When_NoSolutions) {
    quadraticEquations nosolve(0, 0, 1);
    ASSERT_TRUE(nosolve.solve());
}

TEST(solve, When_NoRealSolutions) {
    quadraticEquations norealsolve(1, 2, 5);
    ASSERT_TRUE(norealsolve.solve());
}

TEST(solve, When_OneSolutions) {
    quadraticEquations onesolve(1, -2, 1);
    ASSERT_TRUE(onesolve.solve());
}

TEST(solve, When_TwoSolutions) {
    quadraticEquations twosolve(1, 5, 6);
    ASSERT_TRUE(twosolve.solve());
}

TEST(solve, When_InfSolutions) {
    quadraticEquations infsolve(0, 0, 0);
    ASSERT_TRUE(infsolve.solve());
}

TEST(solve, When_aIsZero) {
    quadraticEquations solveme(0, 1, 1);
    ASSERT_TRUE(solveme.solve());
}

TEST(solve, When_DiskIsOne) {
    quadraticEquations dd(1, 2, 1);
    ASSERT_TRUE(dd.solve());
}