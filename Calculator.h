#ifndef LABS_FIRST_TERM_CALCULATOR_H
#define LABS_FIRST_TERM_CALCULATOR_H

#include <iostream>
#include <string>
#include "stack_on_array.h"
#include "expression.h"
#include "queue_on_nodes.h"

class Calculator {
public:
    explicit Calculator(const std::string&);
    // void InputExpression(std::string);
    void Calculate();
    void Print() const;
private:
    bool isProper_ = false;
    double result = 0;
    std::string expression_;
    stack_on_array<Expression> stack_rpn_;
    QueueOnNodes<Expression> out_str_;
    void RPN();
    static std::string ProcessExpression(std::string);
    static bool IsNumber(char c);
    static bool CheckExpression(const std::string& expression);
};

#endif //LABS_FIRST_TERM_CALCULATOR_H
