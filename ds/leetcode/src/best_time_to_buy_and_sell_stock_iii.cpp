//
// Created by sajith on 10/24/21.
//

#include "base.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        auto n = prices.size();
        if (n < 2) return 0;

        int p1 = prices[0], p2 = prices[n - 1], j;
        vector<int> profit1(n, 0), profit2(n, 0);

        for (int i = 1; i < n; ++i)
        {
            profit1[i] = max(profit1[i - 1], prices[i] - p1);
            p1 = min(p1, prices[i]);

            j = n - 1 - i;
            profit2[j] = max(profit2[j + 1], p2 - prices[j]);
            p2 = max(p2, prices[j]);

        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, profit2[i] + profit1[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {3, 3, 5, 0, 0, 3, 1, 4};
    Solution solution;
    cout << solution.maxProfit(v) << endl;

//    for (auto it = v.rbegin() + 1; it != v.rend(); ++it)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
    return 0;
}
