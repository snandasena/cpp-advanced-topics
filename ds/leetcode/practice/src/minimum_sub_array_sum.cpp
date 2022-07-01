//
// Created by sajith on 6/30/22.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen2(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        bool flag = false;
        for (int i = 0; i < nums.size(); ++i)
        {
            int curr = 0;
            int cur_length = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                curr += nums[j];
                ++cur_length;
                if (curr >= target)
                {
                    flag = true;
                    break;
                }
            }

            if (curr >= target)
            {
                ans = min(ans, cur_length);
            }
        }

        if (flag) return ans;
        return 0;
    }

    int minSubArrayLen(int target, vector<int> &nums)
    {
        vector<int> sum(nums.size() + 1, 0);

        for (int i = 1; i <= nums.size(); ++i)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        int to_find;
        int ans = INT_MAX;
        for (int i = 1; i <= nums.size(); ++i)
        {
            to_find = target + sum[i - 1];
            auto bound = lower_bound(sum.begin(), sum.end(), to_find);
            if (bound != sum.end())
            {
                ans = min(ans, static_cast<int > (bound - sum.begin() + i - 1));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    Solution solution;
    vector<int> v{2, 3, 1, 2, 4, 3};
    cout << solution.minSubArrayLen(7, v);
    return 0;
}