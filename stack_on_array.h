#ifndef LABS_FIRST_TERM_STACK_ON_ARRAY_H
#define LABS_FIRST_TERM_STACK_ON_ARRAY_H

#include <iostream>
#include <ostream>

template<typename T>
class stack_on_array {
public:
    void push(T element);

    T pop();

    T *head();

    int getCounter();

    bool isEmpty();

    void print(std::ostream &out);

    stack_on_array() : stack_(nullptr), counter_(0) {}

    stack_on_array(const stack_on_array &stack) {
        stack_ = new T[stack.counter];
        for (int i = 0; i < counter_; ++i) {
            stack_[i] = stack.stack[i];
        }
    }

    ~stack_on_array() {
        if (counter_ > 0) delete[] stack_;
    }

    stack_on_array &operator=(const stack_on_array &stack) {
        if (counter_ > 0) {
            counter_ = 0;
            delete[] stack_;
        }
        stack_ = new T[stack.counter_];
        counter_ = stack.counter_;
        for (int i = 0; i < counter_; ++i) {
            stack_[i] = stack.stack_[i];
        }
        return *this;
    }

    void operator<<(T element) {
        push(element);
    }

    void operator>>(T &to) {
        to = *head();
        pop();
    }

    bool operator<(stack_on_array<T> stack) {
        return counter_ < stack.counter_;
    }

    bool operator==(stack_on_array<T> stack) {
        return counter_ == stack.counter_;
    }

    T operator[](int t) {
        return stack_[t];
    }

private:
    T *stack_;
    int counter_;


};

template<typename T>
void stack_on_array<T>::push(T element) {
    T *temp;
    temp = stack_;
    stack_ = new T[counter_ + 1];
    counter_++;
    for (int i = 0; i < counter_ - 1; ++i) {
        stack_[i] = temp[i];
    }
    stack_[counter_ - 1] = element;
    if (counter_ > 1) delete[] temp;
}

template<typename T>
T stack_on_array<T>::pop() {
    if (counter_ == 0)
        throw std::logic_error("The stack is empty");
    int temp = counter_;
    counter_--;
    return stack_[temp - 1];
}

template<typename T>
T *stack_on_array<T>::head() {
    if (counter_ == 0) return 0;
    return stack_ + counter_ - 1;
}

template<typename T>
int stack_on_array<T>::getCounter() {
    return counter_;
}

template<typename T>
bool stack_on_array<T>::isEmpty() {
    return (counter_ == 0);
}

template<typename T>
void stack_on_array<T>::print(std::ostream &out) {
    for (int i = counter_ - 1; i > -1; --i) {
        out << stack_[i] << " ";
    }
}

#endif //LABS_FIRST_TERM_STACK_ON_ARRAY_H
