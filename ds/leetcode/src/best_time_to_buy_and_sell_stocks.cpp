//
// Created by sajith on 10/15/21.
//

#include "base.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1) return 0;
        int A = 0, B = -prices[0], C = 0, tmp;

        for (int i = 1; i < prices.size(); ++i)
        {
            tmp = A;
            A = max(A, C);
            C = B + prices[i];
            B = max(B, tmp - prices[i]);
        }

        return max(A, C);
    }
};