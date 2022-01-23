//
// Created by sajith on 1/23/22.
//

#include "base.h"

class Solution
{
    vector<int> ans;

    void dfs(int low, int high, int i, int num)
    {
        if (num >= low && num <= high)
        {
            ans.push_back(num);
        }

        if (num > high || i > 9)
        {
            return;
        }
        dfs(low, high, i + 1, num * 10 + i);
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        for (int i = 1; i < 10; ++i)
        {
            dfs(low, high, i, 0);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    Solution sol;
    vector<int> ans = sol.sequentialDigits(1000, 13000);
    for_each(ans.begin(), ans.end(), [](int i) { cout << i << '\t'; });
    return 0;
}