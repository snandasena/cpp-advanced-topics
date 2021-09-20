//
// Created by sajith on 9/20/21.
//

#include "base.h"


bool isBadVersion(int version); // dummy API


class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 0;
        int r = n;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
            {
                r = mid;
            } else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};