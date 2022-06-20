//
// Created by sajith on 6/20/22.
//

#include "base.h"

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        set<string> good(words.begin(), words.end());
        for (const auto &word: words)
        {
            for (int i = 1; i < word.length(); ++i)
            {
                good.erase(word.substr(i));
            }
        }

        int ans = 0;
        for (const auto &item: good)
        {
            ans += item.length() + 1;
        }
        return ans;
    }
};