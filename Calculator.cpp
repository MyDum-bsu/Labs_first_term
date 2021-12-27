#include "Calculator.h"

bool IsPartOfNumber(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}

double Calculator::Calculate() {
    if (!isProper_) {
        std::cout << "Wrong expression!" << std::endl;
        return 0;
    }
    RPN();
    stack_on_array<Expression> numbers;
    while (!out_str_.isEmpty()) {
        if (out_str_.front().GetType() == Expression::kNumber) {
            numbers.push(out_str_.pop());
        } else {
            Expression rhs = numbers.pop();
            Expression lhs = numbers.pop();
            double value = Expression::Calculate(lhs, rhs, out_str_.pop());
            numbers.push(Expression(std::to_string(value)));
        }
    }
    result = std::stod(numbers.pop().GetValue());
    return result;
}

void Calculator::RPN() {
    Expression expr;
    std::string element;
    for (char element_: expression_) {
        element = element_;
        if (expr.GetType() != Expression::kNULL) {
            if (expr.GetType() == Expression::kNumber && IsPartOfNumber(element_)) {
                expr.Push(element_);
            } else {
                if (expr.GetType() == Expression::kNumber) {
                    out_str_.push(expr);
                } else if (expr.GetType() == Expression::kOpenBracket) {
                    stack_rpn_.push(expr);
                } else if (expr.GetType() == Expression::kCloseBracket) {
                    while (stack_rpn_.head()->GetType() != Expression::kOpenBracket) {
                        out_str_.push(stack_rpn_.pop());
                    }
                    stack_rpn_.pop();
                } else {
                    while (!stack_rpn_.isEmpty() && stack_rpn_.head()->GetPriority() >= expr.GetPriority() &&
                           stack_rpn_.head()->GetType() != Expression::kOpenBracket) {
                        out_str_.push(stack_rpn_.pop());
                    }

                    stack_rpn_.push(expr);
                }
                expr.Set(element);
            }
        } else {
            expr.Set(element);
        }
    }
    if (!expr.IsNull()) {
        if (expr.GetType() == Expression::kNumber) {
            out_str_.push(expr);
        } else if (expr.GetType() == Expression::kOpenBracket) {
            stack_rpn_.push(expr);
        } else if (expr.GetType() == Expression::kCloseBracket) {
            while (stack_rpn_.head()->GetType() != Expression::kOpenBracket) {
                out_str_.push(stack_rpn_.pop());
            }
            stack_rpn_.pop();
        } else {
            while (!stack_rpn_.isEmpty() && stack_rpn_.head()->GetPriority() >= expr.GetPriority() &&
                   stack_rpn_.head()->GetType() != Expression::kOpenBracket) {
                out_str_.push(stack_rpn_.pop());
            }
            stack_rpn_.push(expr);
        }
    }
    while (!stack_rpn_.isEmpty()) {
        out_str_.push(stack_rpn_.pop());
    }
}

std::string Calculator::ProcessExpression(std::string expression) {
    if (expression[0] == '-' || expression[0] == '+') {
        expression.insert(0, "0");
    }
    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(' && (expression[i + 1] == '-' || expression[i + 1] == '+')) {
            expression.insert(i + 1, "0");

        }

        size_t pos = expression.find("+-");
        if (pos != std::string::npos)
            expression.replace(pos, 2, "+0-");
        pos = expression.find("-+");
        if (pos != std::string::npos)
            expression.replace(pos, 2, "-");
        pos = expression.find("--");
        if (pos != std::string::npos)
            expression.replace(pos, 2, "+");
        pos = expression.find("++");
        if (pos != std::string::npos)
            expression.replace(pos, 2, "+");
    }
    return expression;


}

bool Calculator::IsNumber(char c) {
    return (c >= '0' && c <= '9');
}

bool Calculator::CheckExpression(const std::string &expression) {
    int number_of_br = 0;
    if (expression[0] == '.') {
        return false;
    }
    for (auto i: expression) {
        if (i == '(') {
            number_of_br++;
        } else if (i == ')') {
            number_of_br--;
            if (number_of_br < 0)
                return false;
        }
    }
    if (number_of_br != 0) {
        return false;
    }
    int numbers = 0;
    int operations = 0;
    bool numberIsActive = false;
    for (char i: expression) {
        if (IsNumber(i) && !numberIsActive) {
            ++numbers;
            numberIsActive = true;
        } else if (!IsNumber(i)) {
            numberIsActive = false;
            if (i == '(' || i == ')')
                continue;
            ++operations;
        }
    }
    return operations + 1 == numbers;
}

Calculator::Calculator(const std::string &string) {
    expression_ = std::move(ProcessExpression(string));
    isProper_ = CheckExpression(expression_);
}

//void Calculator::Print() const {
//    std::cout << result << std::endl;
//}
//
//int main() {
//    std::string s;
//    // std::string genius = "0";
////    genius += "+10^0";
//    //for (int i = 0; i < 1e4; ++i) {
//    //  genius += "+10^(-6)";
//    //}
//
//    //Calculator b(genius);
//    //b.Calculate();
//    //b.Print();
//    //return 0;
////    a:
//    std::cin >> s;
//    Calculator a(s);
//    std::cout << a.Calculate();
////    goto a;
//    return 0;
//}
