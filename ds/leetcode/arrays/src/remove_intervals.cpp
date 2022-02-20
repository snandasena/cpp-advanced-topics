//
// Created by sajith on 2/20/22.
//

#include "base.h"

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto &v1, auto &v2)
        {
            return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
        });
        auto N = static_cast<int> (intervals.size());
        auto curr = intervals[0];
        int ans = 1;
        for (int i = 1; i < N; ++i)
        {
            if (intervals[i][0] >= curr[0] && intervals[i][1] <= curr[1]) { continue; }
            else
            {
                curr = intervals[i];
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v{{1, 4},
                          {3, 6},
                          {2, 8}};

    Solution solution;
    cout << solution.removeCoveredIntervals(v) << endl;
    return 0;
}