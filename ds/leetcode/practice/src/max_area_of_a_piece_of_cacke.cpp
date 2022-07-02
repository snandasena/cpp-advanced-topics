//
// Created by sajith on 7/2/22.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
    static constexpr int MOD = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.emplace_back(0);
        horizontalCuts.emplace_back(h);

        verticalCuts.emplace_back(0);
        verticalCuts.emplace_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int a = 0;
        for (int i = 0; i < horizontalCuts.size() - 1; ++i)
        {
            a = max(a, horizontalCuts[i + 1] - horizontalCuts[i]);
        }

        int b = 0;
        for (int i = 0; i < verticalCuts.size() - 1; ++i)
        {
            b = max(b, verticalCuts[i + 1] - verticalCuts[i]);
        }

        return ((long long) a * (long long) b) % MOD;
    }
};

int main()
{
    Solution solution;
    vector<int> hori{2};
    vector<int> ver{2};
    cout << solution.maxArea(1000000000, 1000000000, hori, ver);

    return 0;
}