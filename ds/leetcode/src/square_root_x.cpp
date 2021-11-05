//
// Created by sajith on 11/5/21.
//
#include "base.h"
using li = long int;

class Solution
{
public:
    int mySqrt(int n)
    {
        int l = 0, r = n;
        li mid, sqr;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            sqr = mid * mid;
            if (sqr == n) return mid;
            else if (sqr > n) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }
};


int main()
{
    Solution solution;
    cout<< solution.mySqrt(8)<<endl;
    return 0;
}