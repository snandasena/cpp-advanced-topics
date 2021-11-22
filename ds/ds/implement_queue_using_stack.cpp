//
// Created by sajith on 11/22/21.
//

#include <bits/stdc++.h>

using namespace std;

// 1, 2, 3, 4, 5, 6, 7
// 7, 6, 5, 4, 3, 2, 1

class MyQueue
{
    stack<int> stck2;
public:
    MyQueue()
    {

    }

    void push(int x)
    {
        if (stck2.empty())
        {
            stck2.push(x);
            return;
        }
        int temp = stck2.top();
        stck2.pop();
        push(x);
        stck2.push(temp);
    }

    int pop()
    {
        int top = stck2.top();
        stck2.pop();
        return top;
    }

    int peek()
    {
        return stck2.top();
    }

    bool empty()
    {
        return stck2.empty();
    }
};