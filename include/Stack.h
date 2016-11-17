// Copyright 2016 Alexandr

#include "List.h"
#ifndef INCLUDE_STACK_H_
#define INCLUDE_STACK_H_

template<typename StackDataType>
class Stack : List<StackDataType> {
    typedef List<StackDataType> Base;

 public:
        Stack();
        Stack(const Stack &rhs);
        void push(StackDataType value);
        void pop();
        StackDataType top();
        bool isEmpty();
};

template<typename StackDataType>
Stack<StackDataType>::Stack() : Base() {
}

template<typename StackDataType>
Stack<StackDataType>::Stack(const Stack &rhs) : Base((Base)rhs) {
}

template<typename StackDataType>
void Stack<StackDataType>::push(StackDataType value) {
    Base::push(value, 0);
}

template<typename StackDataType>
void Stack<StackDataType>::pop() {
    Base::removeElem(0);
}

template<typename StackDataType>
StackDataType Stack<StackDataType>::top() {
    return Base::operator[](0);
}

template<typename StackDataType>
bool Stack<StackDataType>::isEmpty() {
    return Base::isEmpty();
}


#endif  // INCLUDE_STACK_H_
