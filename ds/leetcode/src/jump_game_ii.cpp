//
// Created by sajith on 8/23/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        size_t n = nums.size();
        if (n == 1)
        {
            return 0;
        }

        int prev_dist = -1;
        int curr_dist = nums[0] + 0;
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i > prev_dist)
            {
                prev_dist = curr_dist;
                ++cnt;
            }

            if (prev_dist >= n - 1)
            {
                return cnt;
            }

            int new_pos = i + nums[i];
            if (new_pos > curr_dist)
            {
                curr_dist = new_pos;
            }
        }
        return cnt;
    }


    int jump1(vector<int> &nums)
    {
        size_t sz = nums.size();
        vector<int> dp(sz, sz + 1);

        dp[0] = 0;
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 1; j <= nums[i]; ++j)
            {
                if (j + i < sz)
                {
                    dp[j + i] = min(dp[j + i], dp[i] + 1);
                } else
                    break;
            }
        }

        return dp[sz - 1];
    }


};