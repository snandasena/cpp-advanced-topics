//
// Created by sajith on 6/30/22.
//

#include <bits/stdc++.h>


using namespace std;


class Solution
{
    int add(int a, int b)
    {
        return a + b;
    }

    int sub(int a, int b)
    {
        return a - b;
    }

    int mul(int a, int b)
    {
        return a * b;
    }

    int dev(int a, int b)
    {
        assert(b == 0);
        return a / b;
    }


public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> st;
        for (const auto &item: tokens)
        {
            st.push(item);
        }

        return 0;
    }
};


int main()
{
    Solution solution;
    vector<string> exp{"2", "1", "+", "3", "*"};
    solution.evalRPN(exp);
    return 0;
}