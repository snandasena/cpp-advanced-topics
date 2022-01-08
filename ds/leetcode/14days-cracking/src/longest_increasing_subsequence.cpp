//
// Created by sajith on 1/8/22.
//

#include "base.h"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp;
        int l;
        int r;
        int mid;
        for (auto const &x: nums)
        {
            if (dp.empty() || dp.back() < x)
            {
                dp.push_back(x);
            }
            else
            {
                if (x <= dp[0])
                {
                    dp[0] = x;
                }
                else
                {
                    l = 0;
                    r = dp.size() - 1;
                    while (l < r)
                    {
                        mid = l + (r -l+ 1)/2;
                        if (dp[mid] < x) l = mid;
                        else r = mid - 1;
                    }
                    dp[r + 1] = x;
                }
            }
        }
        return static_cast<int>(dp.size());
    }
};

int main()
{
    Solution sol;
    vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(v) << endl;
    return 0;
}