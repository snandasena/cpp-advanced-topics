//
// Created by sajith on 11/14/21.
//

#include "base.h"

class CombinationIterator
{
    string s;
    queue<string> que;

    void getCombination(int start, int len, string const &txt)
    {
        if (len == 0)
        {
            que.push(txt);
            return;
        }

        for (int i = start; i <= s.length() - len; ++i)
        {
            getCombination(i + 1, len - 1, txt + s[i]);
        }
    }

public:
    CombinationIterator(string characters, int combinationLength):s(characters)
    {
        getCombination(0, combinationLength, "");
    }

    string next()
    {
        string str = que.front();
        que.pop();
        return str;
    }

    bool hasNext()
    {
        return !que.empty();
    }
};