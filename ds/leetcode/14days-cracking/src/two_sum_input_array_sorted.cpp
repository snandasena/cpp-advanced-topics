//
// Created by sajith on 9/22/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;

        while (l < r)
        {
            int t = numbers[l] + numbers[r];
            if (t == target)
            {
                return {++l, ++r};
            } else if (t < target)
            {
                ++l;
            } else
            {
                r--;
            }
        }

        return {};
    }
};