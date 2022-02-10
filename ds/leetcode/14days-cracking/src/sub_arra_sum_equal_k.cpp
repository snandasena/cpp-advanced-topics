
//
// Created by sajith on 2/10/22.
//

#include "base.h"


class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        auto N = static_cast<int >(nums.size());
        int ans = 0;
        int sum = 0;
        int need;
        unordered_map<int, int> cache;
        cache[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            sum += nums[i];
            if (need = sum - k; cache.count(need))
            {
                ans += cache[need];
            }
            cache[sum] = cache.count(sum) ? cache[sum] + 1 : 1;
        }
        return ans;
    }
};