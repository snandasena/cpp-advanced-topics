//
// Created by sajith on 7/10/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canChange(string start, string target)
    {
        vector<pair<char, int>> S;
        vector<pair<char, int>> T;

        int i = 0;
        for (const auto &item: start)
        {
            if (item != '_')
            {
                S.emplace_back(item, i);
            }
            ++i;
        }

        i = 0;
        for (const auto &item: target)
        {
            if (item != '_')
            {
                T.emplace_back(item, i);
            }
            ++i;
        }

        i = 0;
        if (S.size() != T.size()) return false;
        for (; i < S.size(); ++i)
        {
            if (S[i].first != T[i].first) return false;

            if (S[i].first == 'L' && S[i].second < T[i].second) return false;
            if (S[i].first == 'R' && S[i].second > T[i].second) return false;
        }
        return true;
    }
};