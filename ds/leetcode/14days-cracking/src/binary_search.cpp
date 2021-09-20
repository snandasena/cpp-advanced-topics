//
// Created by sajith on 9/20/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l +(r - l) / 2;
            if (target == nums[mid])
            {
                return mid;
            } else if (target < nums[mid])
            {
                r = mid - 1;
            } else
            {
                l = mid + 1;
            }
        }

        return -1;
    }
};