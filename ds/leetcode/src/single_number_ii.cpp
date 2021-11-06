//
// Created by sajith on 11/6/21.
//

#include "base.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int x = 0;
        for (int &i: nums)
        {
            x ^= i;
        }

        return x;
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    Solution solution;
    solution.singleNumber(nums);
    return 0;
}