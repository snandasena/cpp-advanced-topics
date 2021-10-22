//
// Created by sajith on 10/22/21.
//

#include "base.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[i - 1])
            {
                profit += prices[i - 1] - buy;
                buy = prices[i];
            }
        }
        profit += prices[prices.size() - 1] - buy;

        return profit;
    }
};

