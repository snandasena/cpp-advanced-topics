//
// Created by sajith on 10/23/21.
//

#include "base.h"

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else if (nums[mid] < nums[r]) r = mid;
            else r--;
        }
        return nums[l];
    }
};

