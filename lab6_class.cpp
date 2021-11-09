#include "lab6_class.h"

correctFraction::correctFraction(int numerator, int denominator) {
    try {
        if (denominator == 0) {
//            std::cout << "Incorrect denominator = 0." << std::endl;
            throw 1;
        } else if (abs(numerator) > abs(denominator)) {
//            std::cout << "Incorrect fraction" << std::endl;
            throw 2;
        } else {
            this->numerator = numerator;
            this->denominator = denominator;
            fractionReduction();
        }
    } catch (int e) {
        if (e == 1) {
            std::cout << "Incorrect denominator = 0.\n";
        } else if (e == 2) {
            std::cout << "Incorrect fraction.\n";
        }
    }
}

correctFraction::correctFraction(const correctFraction &clone) {
    this->numerator = clone.numerator;
    this->denominator = clone.denominator;
}

void correctFraction::fractionReduction() {
    for (int i = std::min(abs(numerator), abs(denominator)); i > 0; --i) {
        if (abs(numerator) % i == 0 && abs(denominator) % i == 0) {
            numerator /= i;
            denominator /= i;
        }
    }
}

int correctFraction::getFractionNumerator() const {
    return numerator;
}

int correctFraction::getFractionDenominator() const {
    return denominator;
}

void correctFraction::sumWithNumber(int number) {
    numerator += number * denominator;
    fractionReduction();
}

void correctFraction::sumWithFraction(const correctFraction& fraction) {
    this->numerator = (this->numerator) * fraction.denominator + fraction.numerator * (this->denominator);
    this->denominator *= fraction.denominator;
    fractionReduction();
}

void correctFraction::multiplyWithNumber(int multiplier) {
    numerator *= multiplier;
    fractionReduction();
}

void correctFraction::multiplyWithFraction(const correctFraction& fraction_) {
    this->numerator *= fraction_.numerator;
    this->denominator *= fraction_.denominator;
    fractionReduction();
}

void correctFraction::divideWithNumber(int divider) {
    if (divider == 0) {
        std::cout << "You can't divide by 0" << std::endl;
        exit(1);
    } else {
        denominator *= divider;
    }
    fractionReduction();
}

void correctFraction::divideWithFraction(const correctFraction& divider) {
    if (divider.numerator == 0) {
        std::cout << "numerator is 0. You can't divide fractions" << std::endl;
        exit(1);
    } else {
        this->numerator *= divider.denominator;
        this->denominator *= divider.numerator;
    }
    fractionReduction();
}

void correctFraction::printFraction() const {
    if (numerator * denominator < 0) {
        std::cout << "-" << abs(numerator) << "/" << abs(denominator) << std::endl;
    } else {
        std::cout << abs(numerator) << "/" << abs(denominator) << std::endl;
    }
}
