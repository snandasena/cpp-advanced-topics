//
// Created by sajith on 11/6/21.
//
#include "base.h"


class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xr = 0;
        for (const int &i: nums)
        {
            xr ^= i;
        }
        return xr;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {2,2,1};
    solution.singleNumber(nums);
    return 0;
}