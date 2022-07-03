//
// Created by sajith on 7/3/22.
//
// you can use includes, for example:
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &str)
{
    // write your code in C++14 (g++ 6.2.0)
    stack<char> st;
    unordered_map<char, char> mp1;
    mp1['('] = ')';
    mp1['{'] = '}';
    mp1['['] = ']';

    unordered_map<char, char> mp2;
    mp2[')'] = '(';
    mp2['}'] = '{';
    mp2[']'] = '[';

    for (const auto &ch: str)
    {

        if (mp1.count(ch) > 0) st.push(ch);
        else
        {
            if (st.empty()) return 0;
            else if (st.top() == mp2.at(ch))
            {
                st.pop();
            }
        };
    }

    if (!st.empty()) return 0;
    return 1;
}


int main()
{
    string str{"{[()()]}"};
    cout << solution(str) << endl;
    return 0;
}