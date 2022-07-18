//
// Created by sajith on 7/17/22.
//


#include "base.h"

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (const auto &query: queries)
        {
            vector<pair<string, int>> v;
            int i = 0;
            for (const auto &item: nums)
            {
                auto str = item.substr(item.size() - query[1]);
                v.emplace_back(str, i);
                ++i;
            }

            sort(v.begin(), v.end());
            auto val = v[query[0] - 1].second;
            ans.push_back(val);

        }
        return ans;
    }
};


int main()
{
    vector<string> v{"24", "37", "96", "04"};
    vector<vector<int>> v2{{2, 1},
                           {2, 2}};

    Solution solution;
    vector<int> ans = solution.smallestTrimmedNumbers(v, v2);

    for (const auto &item: ans)
    {
        cout << item << '\t';
    }
    return 0;
}