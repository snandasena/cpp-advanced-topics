//
// Created by sajith on 6/30/22.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        map<int, int> mp;

        for (const auto &item: nums)
        {
            ++mp[item];
        }

        vector<int> ans;

        for (auto &[f, s]: mp)
        {
            if (s > nums.size() / 3)
            {
                ans.push_back(f);
            }
        }

        return ans;
    }
};