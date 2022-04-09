//
// Created by sajith on 4/9/22.
//

#include "base.h"


class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (const auto &item: nums)
        {
            mp[item]++;
        }

        priority_queue<pair<int, int>> pq;
        for (const auto &[f, s]: mp)
        {
            pq.emplace(s, f);
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};


int main()
{
    Solution solution;
    vector<int> v{1, 1, 1, 2, 2, 3};
    solution.topKFrequent(v, 2);
    return 0;
}