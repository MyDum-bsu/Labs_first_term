#pragma once

#include <iostream>

class correctFraction {
public:
    correctFraction(int numerator, int denominator);

    correctFraction(const correctFraction &clone);

    void fractionReduction();

    int getFractionNumerator() const;

    int getFractionDenominator() const;

    void sumWithNumber(int number);

    void sumWithFraction(const correctFraction& fraction);

    void multiplyWithNumber(int multiplier);

    void multiplyWithFraction(const correctFraction& fraction_);

    void divideWithNumber(int divider);

    void divideWithFraction(const correctFraction& divider);

    void printFraction() const;
private:
    int numerator;
    int denominator;
};
