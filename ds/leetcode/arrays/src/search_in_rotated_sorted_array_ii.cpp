//
// Created by sajith on 2/20/22.
//

#include "base.h"

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int end = static_cast<int > (nums.size());
        if (end == 0) return false;
        int start = 0;
        --end;
        int mid;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;

            if (nums[start] == nums[mid])
            {
                ++start;
                continue;
            }

            bool pivotArr = nums[start] <= nums[mid];
            bool targetArr = nums[start] <= target;
            if (pivotArr ^ targetArr)
            {
                if (pivotArr) start = mid + 1;
                else end = mid - 1;
            }
            else
            {
                if (nums[mid] < target) start = mid + 1;
                else end = mid - 1;
            }
        }
        return false;
    }
};