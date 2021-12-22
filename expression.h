#ifndef LABS_FIRST_TERM_EXPRESSION_H
#define LABS_FIRST_TERM_EXPRESSION_H

#include <string>
#include <stdexcept>
#include <cmath>
class Expression {
public:
    Expression() = default;
    enum exType {
        kNULL,
        kNumber,
        kPlus,
        kMinus,
        kMultiply,
        kDivide,
        kPower,
        kOpenBracket,
        kCloseBracket
    };
    explicit Expression(std::string s);
    void Push(char c);
    int GetPriority() const;
    exType GetType() const;
    std::string GetValue() const;
    bool IsNull() const;
    void Set(std::string s);
    static double Calculate(const Expression& left, const Expression& right, const Expression& operation);
private:
    exType type_ = kNULL;
    std::string value_ = "NULL";
};


#endif //LABS_FIRST_TERM_EXPRESSION_H
