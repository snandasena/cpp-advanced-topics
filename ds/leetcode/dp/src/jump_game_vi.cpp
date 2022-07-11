//
// Created by sajith on 7/9/22.
//


#include "base.h"

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size());
        dp.back() = nums.back();
        priority_queue<pair<int, int>> pq;

        pq.push({dp.back(), nums.size() - 1});

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            while (!pq.empty() && pq.top().second > i + k)
            {
                pq.pop();
            }

            dp[i] = pq.top().first + nums[i];
            pq.push({dp[i], i});
        }
        return dp.front();
    }
};


int main()
{
    Solution solution;
    vector<int> v{10, -5, -2, 4, 0, 3};
    int k = 3;

    cout << solution.maxResult(v, k);
    return 0;
}