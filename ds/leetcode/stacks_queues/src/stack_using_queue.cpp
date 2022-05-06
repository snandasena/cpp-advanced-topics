//
// Created by sajith on 5/5/22.
//

#include "base.h"

// 1,3,4,5,6 // q1
// 6,5,4,3,1 // q2
class MyStack
{
    queue<int> q2;

public:
    MyStack()
    {

    }

    void push(int x)
    {
        q2.push(x);
        auto sz = q2.size();
        for (auto i = 0; i < sz - 1; ++i)
        {
            q2.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        auto t = q2.front();
        q2.pop();
        return t;
    }

    int top()
    {
        return q2.front();
    }

    bool empty()
    {
        return q2.empty();
    }
};