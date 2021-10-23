//
// Created by sajith on 10/23/21.
//

#include "base.h"

class Solution
{
    // 4,5,6,7,0,1,2
public:
    int findMin2(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];
        int l = 0;
        int r = nums.size() - 1;
        if (nums[r] > nums[0]) return nums[0];
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }

            if (nums[mid - 1] > nums[mid])
            {
                return nums[mid];
            }

            if (nums[mid] > nums[0])
            {
                l = mid + 1;
            } else
            {
                r = mid - 1;
            }
        }
        return -1;
    }

    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1, mid;

        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }

};