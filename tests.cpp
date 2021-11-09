#include "gtest/gtest.h"
#include "lab6_class.h"

TEST(fractionReduction, cut) {
    correctFraction cutIt(3, 6);
    ASSERT_EQ(cutIt.getFractionNumerator(), 1);
    ASSERT_EQ(cutIt.getFractionDenominator(), 2);
}

TEST(sum, When_SumWithNumber) {
    correctFraction sumIt(4, 7);
    sumIt.sumWithNumber(4);
    ASSERT_EQ(sumIt.getFractionNumerator(), 32);
    ASSERT_EQ(sumIt.getFractionDenominator(), 7);
}

TEST(sum, When_SumWithFraction) {
    correctFraction sumIt(5, 20);
    correctFraction withIt(3, 4);
    sumIt.sumWithFraction(withIt);
    ASSERT_EQ(sumIt.getFractionNumerator(), 1);
    ASSERT_EQ(sumIt.getFractionDenominator(), 1);
}

TEST(multiply, When_MultiplyWithNumber) {
    correctFraction multMe(7, 8);
    multMe.multiplyWithNumber(16);
    ASSERT_EQ(multMe.getFractionNumerator(), 14);
    ASSERT_EQ(multMe.getFractionDenominator(), 1);
}

TEST(multiply, When_MultiplyWithFraction) {
    correctFraction multMe(13, 17);
    correctFraction withMe(34, 169);
    multMe.multiplyWithFraction(withMe);
    ASSERT_EQ(multMe.getFractionNumerator(), 2);
    ASSERT_EQ(multMe.getFractionDenominator(), 13);
}

TEST(divide, When_divideWithNumber) {
    correctFraction divMe(7, 8);
    divMe.divideWithNumber(7);
    ASSERT_EQ(divMe.getFractionNumerator(), 1);
    ASSERT_EQ(divMe.getFractionDenominator(), 8);
}

TEST(divide, When_divideWithFraction) {
    correctFraction divMe(7, 8);
    correctFraction withMe(3, 5);
    divMe.divideWithFraction(withMe);
    ASSERT_EQ(divMe.getFractionNumerator(), 35);
    ASSERT_EQ(divMe.getFractionDenominator(), 24);
}

//TEST(divide, When_divideWithZero) {
//    correctFraction divMe(7, 8);
//    divMe.divideWithNumber(0);
//}

//TEST(incorrect, When_DenominatorIsZero) {
//    correctFraction divMe(7, 0);
//    }
//
//TEST(incorrect, When_DenominatorLessThanNumerator) {
//    correctFraction divMe(11, 9);
//}

