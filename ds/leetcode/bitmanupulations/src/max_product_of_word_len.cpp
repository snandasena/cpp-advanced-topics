//
// Created by sajith on 5/29/22.
//

#include "base.h"


class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> wVec(words.size());
        int wInt;
        for (size_t i = 0; i < words.size(); ++i)
        {
            wInt = 0;
            for (const auto &ch: words[i])
            {
                wInt |= 1 << (ch - 'a');
            }
            wVec[i] = wInt;
        }

        int ans = 0;
        for (size_t i = 0; i < words.size()-1; ++i)
        {
            for (size_t j = i + 1; j < words.size(); ++j)
            {
                if ((wVec[i] & wVec[j]) == 0)
                {
                    ans = max(ans, static_cast<int > (words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};