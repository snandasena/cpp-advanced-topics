//
// Created by sajith on 6/12/22.
//


#include "base.h"

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int curr = 0;
        int ans = 0;
        unordered_set<int> cache;
        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            while (cache.count(nums[j]) > 0)
            {
                cache.erase(nums[i]);
                curr -= nums[i];
                ++i;
            }

            curr += nums[j];
            cache.insert(nums[j]);
            ans = max(ans, curr);
            ++j;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> v{10000,1,10000,1,1,1,1,1,1};
//    vector<int> v{4, 2, 4, 5, 6};

    cout << solution.maximumUniqueSubarray(v) << endl;

    return 0;
}