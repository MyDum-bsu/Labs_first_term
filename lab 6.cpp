#include "lab6_class.h"

int main() {
    correctFraction fraction(3, 4);
    fraction.sumWithNumber(2);
    fraction.printFraction();

    correctFraction fraction_(-3, 6);
    fraction_.multiplyWithFraction(fraction);
    fraction_.printFraction();

    correctFraction frac(12, 16);
    frac.sumWithFraction(fraction_);
    frac.printFraction();

    correctFraction drob(4, -6);
    drob.multiplyWithNumber(6);
    drob.printFraction();

    correctFraction drob_(4, -6);
    drob_.divideWithNumber(8);
    drob_.printFraction();

    correctFraction lastdrob(2, 5);
    lastdrob.divideWithFraction(fraction);
    lastdrob.printFraction();
    return 0;
}