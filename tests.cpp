#include "gtest/gtest.h"
#include "Calculator.h"

TEST(Calculator, When_easy_expression) {
    std::string s1 = "2+2";
    std::string s2 = "2+2*2";
    std::string s3 = "2*2+2";
    Calculator a(s1);
    Calculator b(s2);
    Calculator c(s3);
    ASSERT_EQ(a.Calculate(), 4);
    ASSERT_EQ(b.Calculate(), 6);
    ASSERT_EQ(c.Calculate(), 6);
}

TEST(Calculator, When_not_eazy_expression) {
    std::string s1 = "(6+10-4)/(1+1*2)+1";
    Calculator a(s1);
    ASSERT_EQ(a.Calculate(), 5);
}


