//
// Created by sajith on 2/20/22.
//
#include "base.h"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int h = static_cast<int >(nums.size()) - 1;
        int mid;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target <= nums[mid])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (target >= nums[mid] && target <= nums[h])
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }

        return -1;
    }
};