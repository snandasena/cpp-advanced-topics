//
// Created by sajith on 10/25/21.
//

#include "base.h"

class MinStack
{
    stack<int> mn_stack;
    stack<int> stack;
public:
    MinStack()
    {

    }

    void push(int val)
    {
        stack.push(val);
        if (mn_stack.empty() || val <= getMin()) mn_stack.push(val);
    }

    void pop()
    {
        if (stack.top() == mn_stack.top()) mn_stack.pop();
        stack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return mn_stack.top();
    }
};