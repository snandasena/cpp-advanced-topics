//
// Created by sajith on 9/22/21.
//

#include "base.h"

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int idx = 0;
        for (int x: nums)
        {
            if (x != 0)
            {
                nums[idx] = x;
                idx++;
            }
        }

        for (int i = idx; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};


int main()
{
    Solution solution;
    vector<int> v = {0, 1, 0, 3, 12};
    solution.moveZeroes(v);
    return 0;
}