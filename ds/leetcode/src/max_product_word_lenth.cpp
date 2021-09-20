//
// Created by sajith on 9/20/21.
//

#include "base.h"

class Solution
{
public:
    int maxProduct1(vector<string> &words)
    {
        vector<vector<int> > v;
        for (auto &str: words)
        {
            vector<int> vnums(26, 0);
            for (auto &c: str)
            {
                vnums[c - 'a']++;
            }
            v.push_back(vnums);
        }

        int ans = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                bool flag = true;
                for (int k = 0; k < 26; ++k)
                {
                    if (v[i][k] > 0 and v[j][k] > 0)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    ans = max(ans, static_cast<int >(words[i].size() * words[j].size()));
                }
            }
        }

        return ans;
    }

    int maxProduct(vector<string> &words)
    {
        vector<int> w_Ints;
        for (auto &str: words)
        {
            int w_Int = 0;
            for (auto &c: str)
            {
                w_Int |= 1 << (c - 'a');
            }
            w_Ints.push_back(w_Int);
        }

        int ans = 0;
        for (int i = 0; i < words.size() - 1; ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if ((w_Ints[i] & w_Ints[j]) == 0)
                {
                    ans = max(ans, static_cast<int> (words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};