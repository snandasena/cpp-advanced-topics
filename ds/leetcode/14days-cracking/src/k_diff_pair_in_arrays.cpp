//
// Created by sajith on 2/9/22.
//

#include "base.h"

class Solution
{
public:
    int findPairs2(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        auto N = static_cast<int>(nums.size());
        int ans = 0;
        unordered_set<int> cache;
        set<pair<int, int>> cache2;
        for (int i = 0; i < N; ++i)
        {
            if (cache.count(nums[i]))
            {
                continue;
            }
            else
            {
                cache.insert(nums[i]);
            }
            for (int j = i + 1; j < N; ++j)
            {
                if (cache2.count({nums[j], nums[i]}))
                {
                    break;
                }
                if ((nums[j] - nums[i]) == k)
                {
                    ++ans;
                    cache2.insert({nums[j], nums[i]});
                }
                else if (nums[j] - nums[i] > k) break;
            }
        }
        return ans;
    }

    int findPairs(vector<int> &nums, int k)
    {
        auto N = static_cast<int> (nums.size());
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 1; j < N; ++j)
        {
            while (i < j && (nums[j] - nums[i]) > k)
            {
                ++i;
            }

            if (i < j && nums[j] - nums[i] == k)
            {
                ++ans;
                while (i + 1 < N && nums[i + 1] == nums[i])
                {
                    ++i;
                }
                ++i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> v{1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    int k = 3;
    LOG(solution.findPairs(v, k));
    return 0;
}