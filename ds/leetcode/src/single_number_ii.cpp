//
// Created by sajith on 11/6/21.
//

#include "base.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        int bits[32] = {0};
        for (int i = 0; i < 32; ++i)
        {
            for (int &num: nums)
            {
                bits[i] += num >> i & 1;
                bits[i] %= 3;
            }
        }

        for (int i = 0; i < 32; ++i)
        {
            res |= (bits[i] << i);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}