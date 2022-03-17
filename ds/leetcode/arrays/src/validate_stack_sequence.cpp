//
// Created by sajith on 3/16/22.
//

#include "base.h"

class Solution
{
public:
    bool validateStackSequences1(vector<int> &pushed, vector<int> &popped)
    {
        auto N = static_cast<int >(pushed.size());
        stack<int> stac;
        int j = 0;
        for (const auto &item : pushed)
        {
            stac.push(item);
            while (!stac.empty() && j < N && stac.top() == popped[j])
            {
                stac.pop();
                ++j;
            }
        }
        return N == j;
    }

    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0;
        int j = 0;
        for (const auto &item : pushed)
        {
            pushed[i] = item;
            ++i;
            while (i > 0 && pushed.at(i - 1) == popped.at(j))
            {
                --i;
                ++j;
            }
        }
        return i == 0;
    }
};