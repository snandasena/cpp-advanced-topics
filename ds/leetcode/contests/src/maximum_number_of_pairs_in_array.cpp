//
// Created by sajith on 7/17/22.
//
#include "base.h"

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        if (nums.size() == 1) return {0, 1};
        unordered_map<int, int> mp;
        for (const auto &item: nums)
        {
            ++mp[item];
        }
        int a = 0;
        int b = 0;
        for (const auto &[first, second]: mp)
        {
            if (second >= 2)
            {
                a += second / 2;
                b += second % 2;
            }else
            {
                ++b;
            }
        }
        return {a, b};
    }
};

int main()
{
    Solution solution;
    vector<int> v{1,2,3,4,5};

    vector<int> ans = solution.numberOfPairs(v);

    cout << ans[0] << " " << ans[1];
    return 0;
}