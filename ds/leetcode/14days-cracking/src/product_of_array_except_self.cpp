
//
// Created by sajith on 11/27/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int postifx = 1;
        vector<int> out(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
        {
            out[i] = postifx;
            postifx *= nums[i];
        }

        postifx = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            out[i] *= postifx;
            postifx *= nums[i];
        }
        return out;
    }
};

int main()
{
    Solution solution;
    vector<int> v{-1,1,0,-3,3};
    auto out = solution.productExceptSelf(v);
    return 0;
}