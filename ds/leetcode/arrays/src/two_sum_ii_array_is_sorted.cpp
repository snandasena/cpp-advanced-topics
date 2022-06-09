//
// Created by sajith on 6/9/22.
//
#include "base.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int l = 0;
        int r = static_cast<int>(numbers.size()) - 1;
        int t;
        while (l < r)
        {
            t = numbers[l] + numbers[r];
            if (t == target) return {++l, ++r};
            else if (t < target)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }

        return {};
    }
};