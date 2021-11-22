//
// Created by sajith on 11/22/21.
//

#include <bits/stdc++.h>

using namespace std;


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
        auto size = q2.size();
        for (int i = 0; i < size - 1; ++i)
        {
            q2.push(q2.front());
            q2.pop();
        }
    }

    int pop()
    {
        int temp = q2.front();
        q2.pop();
        return temp;
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