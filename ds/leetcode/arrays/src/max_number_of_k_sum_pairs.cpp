//
// Created by sajith on 5/4/22.
//
#include "base.h"

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (const auto &item: nums)
        {
            mp[item]++;
        }
        int ans = 0;
        for (const auto &item: nums)
        {
            if (k - item != item)
            {
                if (mp[item] > 0 && mp[k - item] > 0)
                {
                    mp[item]--;
                    mp[k - item]--;
                    ++ans;
                }
            }
            else
            {
                if (mp[item] >= 2)
                {
                    mp[item] -= 2;
                    ++ans;
                }
            }

        }

        return ans;
    }
};

int main()
{
    vector<int> v{3, 1, 3, 4, 3};
    int k = 6;
    Solution sol;
    cout << sol.maxOperations(v, k) << endl;
    return 0;
}