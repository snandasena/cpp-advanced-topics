//
// Created by sajith on 9/20/21.
//

#include "base.h"

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int position = nums.size();
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (target == nums[mid])
            {
                return mid;
            } else if (nums[mid] > target)
            {
                r = mid - 1;
                position = mid;
            } else
            {
                l = mid + 1;
            }
        }
        return position;
    }
};

int main()
{
    vector<int> v = {1, 3, 5, 6};

    Solution solution;
    solution.searchInsert(v, 7);
    return 0;
}