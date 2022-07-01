//
// Created by sajith on 6/30/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    using LI = long long int;
public:
    bool containsNearbyAlmostDuplicate2(vector<int> &nums, int k, int t)
    {
        set<int> ss(nums.begin(), nums.end());
        if (t == 0 && ss.size() == nums.size()) return false;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < i + k + 1 && j < nums.size(); ++j)
            {
                if (abs(static_cast<LI>(nums[i]) - static_cast<LI>(nums[j])) <= t) return true;
            }
        }

        return false;
    }

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i)
        {
            v.emplace_back(nums[i], i);
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                LI p = abs(static_cast<LI>(v[i].first) - v[j].first);
                if (p <= t)
                {
                    if (abs(v[i].second - v[j].second) <= k)
                    {
                        return true;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return false;
    }
};