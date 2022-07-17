//
// Created by sajith on 7/17/22.
//


#include "base.h"

class Solution
{

    int sum(int i)
    {
        int ans = 0;
        while (i)
        {
            ans += (i % 10);
            i /= 10;
        }

        return ans;
    }
public:
    int maximumSum(vector<int> &nums)
    {
        vector<pair<int, int>> v;
        for (const auto &item: nums)
        {
            v.emplace_back(item, sum(item));
        }
        sort(v.begin(), v.end(), [](pair<int, int> &p1, pair<int, int> &p2)
        {
            if (p1.second == p2.second)
            {
                return p1.first > p2.first;
            }
            return p1.second > p2.second;
        });

        int ans = -1;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            if (v[i].second == v[i + 1].second)
            {
                ans = max(ans, v[i].first + v[i + 1].first);
            }
        }
        return ans;
    }
};

int main()
{

    Solution solution;
    vector<int> v{229, 398, 269, 317, 420, 464, 491, 218, 439, 153, 482, 169, 411, 93, 147, 50, 347, 210, 251, 366,
                  401};
    cout << solution.maximumSum(v);
    return 0;
}