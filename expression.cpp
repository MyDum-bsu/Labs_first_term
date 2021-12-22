#include "expression.h"

Expression::Expression(std::string s) : value_(std::move(s)) {
    if (value_.length() == 1) {
        if (value_ == "+")
            type_ = kPlus;
        else if (value_ == "-")
            type_ = kMinus;
        else if (value_ == "*")
            type_ = kMultiply;
        else if (value_ == "/")
            type_ = kDivide;
        else if (value_ == "^")
            type_ = kPower;
        else if (value_[0] >= '0' && value_[0] <= '9')
            type_ = kNumber;
        else if (value_ == ")")
            type_ = kCloseBracket;
        else if (value_ == "(")
            type_ = kOpenBracket;
        else
            type_ = kNULL;
    } else {
        type_ = kNumber;
        for (auto i: value_) {
            if (i != '.' && (i < '0' || i > '9'))
                if (i != value_[0] && i == '-')
                    type_ = kNULL;
        }
    }
}

void Expression::Push(char c) {
    value_.push_back(c);
}

int Expression::GetPriority() const {
    if (type_ == kNumber) {
        return 0;
    } else if (type_ == kPlus || type_ == kMinus) {
        return 1;
    } else if (type_ == kMultiply || type_ == kDivide) {
        return 2;
    } else if (type_ == kPower) {
        return 3;
    } else {
        return 4;
    }
}

Expression::exType Expression::GetType() const {
    return type_;
}

std::string Expression::GetValue() const {
    return value_;
}

bool Expression::IsNull() const {
    return type_ == kNULL;
}

void Expression::Set(std::string s) {
    value_ = s;
    if (value_.length() == 1) {
        if (value_ == "+")
            type_ = kPlus;
        else if (value_ == "-")
            type_ = kMinus;
        else if (value_ == "*")
            type_ = kMultiply;
        else if (value_ == "/")
            type_ = kDivide;
        else if (value_ == "^")
            type_ = kPower;
        else if (value_[0] >= '0' && value_[0] <= '9')
            type_ = kNumber;
        else if (value_ == ")")
            type_ = kCloseBracket;
        else if (value_ == "(")
            type_ = kOpenBracket;
        else
            type_ = kNULL;
    } else {
        type_ = kNumber;
        for (auto i: value_) {
            if (i != '.' && (i < '0' || i > '9'))
                if (i != value_[0] && i == '-')
                    type_ = kNULL;
        }
    }
}

double Expression::Calculate(const Expression &left, const Expression &right, const Expression &operation) {
    if (left.GetType() != kNumber || right.GetType() != kNumber) {
        throw std::logic_error("Wrong input");
    }
    double left_val = std::stod(left.GetValue());
    double right_val = std::stod(right.GetValue());
    switch (operation.GetType()) {
        case kPlus : {
            return left_val + right_val;
        }
        case kMinus : {
            return left_val - right_val;
        }
        case kMultiply : {
            return left_val * right_val;
        }
        case kDivide : {
            if (right_val == 0) {
                throw std::logic_error("Can't divide by zero");
            }
            return left_val / right_val;
        }
        case kPower : {
            if (left_val == 0 && right_val) {
                throw std::logic_error("Wrong expression 0^0");
            }
            return pow(left_val, right_val);
        }
    }
    return 0;
}

