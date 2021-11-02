#pragma once

#include <iostream>

class correctFraction {
public:
    correctFraction(int numerator, int denominator);

    correctFraction(const correctFraction &clone);

    bool fractionReduction();

    int getFractionNumerator();

    int getFractionDenominator();

    bool sumWithNumber(int number);

    bool sumWithFraction(correctFraction fraction);

    bool multiplyWithNumber(int multiplier);

    bool multiplyWithFraction(correctFraction fraction_);

    bool divideWithNumber(int divider);

    bool divideWithFraction(correctFraction divider);

    bool printFraction();
private:
    int numerator;
    int denominator;
};
