//
// Created by sajith on 6/30/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};