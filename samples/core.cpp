// Copyright 2016 Alexandr
#include "Stack.h"
#include <iostream>

int main() {
    Stack<int> stk;
    for (int i = 0; i < 15; i++)
        stk.push(i);
    while (!stk.isEmpty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}
