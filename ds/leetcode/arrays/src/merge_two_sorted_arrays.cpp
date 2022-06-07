//
// Created by sajith on 6/7/22.
//
#include "base.h"

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        auto last = m + n - 1;
        while (n > 0 && m > 0)
        {
            if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[last] = nums1[m - 1];
                --m;
            }
            else
            {
                nums1[last] = nums2[n - 1];
                --n;
            }

            --last;
        }

        while (n > 0)
        {
            nums1[last] = nums2[n-1];
            --n;
            --last;
        }
    }
};