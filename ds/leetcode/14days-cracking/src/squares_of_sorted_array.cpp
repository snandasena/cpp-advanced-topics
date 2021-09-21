//
// Created by sajith on 9/21/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, position = nums.size();
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= 0)
            {
                position = mid;
                r = mid - 1;
            } else
            {
                l = mid + 1;
            }
        }

        vector<int> ans;
        int negativePosition = position - 1;

        while (position < nums.size() or negativePosition >= 0)
        {
            int left = (negativePosition >= 0) ? 0 - nums[negativePosition] : INT_MAX;
            int right = (position < nums.size()) ? nums[position] : INT_MAX;

            if (left < right)
            {
                negativePosition--;
                ans.push_back(left * left);
            } else
            {
                position++;
                ans.push_back(right * right);
            }
        }
        return ans;
    }
};