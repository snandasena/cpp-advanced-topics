//
// Created by sajith on 11/20/21.
//

#include "base.h"

class Solution1
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {

        int x = 0;
        for (int const &i: nums) x ^= i;

        return x;
    }
};

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];
        return snd(nums, 0, nums.size() - 1);
    }

    int snd(vector<int> &nums, int a, int b)
    {
        int mid = (a + b) / 2;
        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) return nums[mid];
        if (mid % 2 == 0)
        {
            if (nums[mid + 1] == nums[mid])
            {
                return snd(nums, mid + 1, b);
            }
            else
            {
                return snd(nums, a, mid - 1);
            }
        }
        else
        {
            if (nums[mid + 1] != nums[mid])
            {
                return snd(nums, mid + 1, b);

            }
            else
            {
                return snd(nums, a, mid - 1);
            }
        }
    }
};