//
// Created by sajith on 7/17/22.
//


#include "base.h"

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int curr = nums[0];
        int mx = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            curr = max(nums[i], curr + nums[i]);
            mx = max(curr, mx);
        }



        return mx;
    }
};

int main()
{
    Solution solution;
    vector<int> v{1, -2, 3, -2};
    cout << solution.maxSubarraySumCircular(v);

    return 0;
}