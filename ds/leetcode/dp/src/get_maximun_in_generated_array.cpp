//
// Created by sajith on 7/8/22.
//

#include "base.h"

vector<int> nums(101, 0);

class Solution
{

public:
    int getMaximumGenerated(int n)
    {
        if (n <= 1) return n;
        nums[1] = 1;
        int ans = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                nums[i] = nums[i / 2];
            }
            else
            {
                nums[i] = nums[i / 2] + nums[i / 2 + 1];
            }

            ans = max(ans, nums[i]);
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    cout << solution.getMaximumGenerated(5);
    return 0;
}