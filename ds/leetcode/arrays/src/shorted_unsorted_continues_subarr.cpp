//
// Created by sajith on 5/3/22.
//

#include "base.h"

class Solution
{
public:
    int findUnsortedSubarray1(vector<int> &nums)
    {
        stack<int> stk;
        int l = nums.size();
        int r = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!stk.empty() && nums[stk.top()] > nums[i])
            {
                l = min(l, stk.top());
                stk.pop();
            }
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i])
            {
                r = max(r, stk.top());
                stk.pop();
            }

            stk.push(i);
        }

        return r - l > 0 ? r - l + 1 : 0;
    }

    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int mx = INT_MIN;
        int begin = -1;
        int end = -1;
        int mn = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            mx = max(mx, nums[i]);
            if (mx > nums[i])
            {
                end = i;
            }
        }


        for (int i = n - 1; i >= 0; --i)
        {
            mn = min(mn, nums[i]);
            if (mn < nums[i])
            {
                begin = i;
            }
        }

        if (begin == end) return 0;
        else return end - begin + 1;
    }
};