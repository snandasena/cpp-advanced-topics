//
// Created by sajith on 10/22/21.
//

#include "base.h"

class Solution
{

public:
    int maxProfit(vector<int> &prices)
    {
        /*
         * Price        : 7,1,5,3,6,4
         * Min Price    : 7,1,1,1,1,1
         * Max Profit   : 0,0,4,4,5,5
         */

        int min_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};