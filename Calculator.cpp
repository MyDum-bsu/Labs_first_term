#include "Calculator.h"

/*int Calculator::getPriority(const std::string &operation) {
//    if (operation == "+" || operation == "-") {
//        return 1;
//    }
//    if (operation == "(" || operation == "(") {
//        return 3;
//    }
//    return 2;
//}
//
//double calculate(double a, double b, const std::string &operation) {
//    if (operation == "+") {
//        return a + b;
//    }
//    if (operation == "-") {
//        return a - b;
//    }
//    if (operation == "*") {
//        return a * b;
//    }
//    if (operation == "/") {
//        if (b == 0) {
//            std::cout << "You can't divide by zero\n";
//        } else {
//            return a / b;
//        }
//    }
//    return -1;
//}
//
//void Calculator::makeOperation() {
//    double a = *numbers_.head();
//    numbers_.pop();
//    double b = *numbers_.head();
//    numbers_.pop();
//    std::string operation = operation_.head();
//    operation_.pop();
//    numbers_.push(calculate(a, b, operation));
//}
//
//void Calculator::RPN() {
//    if (string_.empty()) {
//        return 0;
//    }
//
//}
*/

bool IsPartOfNumber(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}

void Calculator::Calculate() {
    if (!isProper_) {
        std::cout << "Wrong expression!" << std::endl;
        return;
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
    for (int i = 0; i < expression.length(); i++) {
        if (IsNumber(expression[i]) && !numberIsActive) {
            ++numbers;
            numberIsActive = true;
        } else if (!IsNumber(expression[i])) {
            numberIsActive = false;
            if (expression[i] == '(' || expression[i] == ')')
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

void Calculator::Print() const {
    std::cout << ">>> " << result << std::endl;
}

int main() {
    std::string s;
    std::cin >> s;
    Calculator a(s);
    a.Calculate();
    a.Print();
    return 0;
}