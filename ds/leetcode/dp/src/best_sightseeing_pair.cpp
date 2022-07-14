//
// Created by sajith on 7/14/22.
//


#include "base.h"

class Solution
{
public:
    int maxScoreSightseeingPair2(vector<int> &values)
    {
        int ans = 0;
        for (int i = 0; i < values.size(); ++i)
        {
            for (int j = i + 1; j < values.size(); ++j)
            {
                auto curr = values[i] + values[j] + i - j;
                ans = max(ans, curr);
            }
        }

        return ans;
    }
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int ans = 0;
        int best_score = 0;
        for (int i = 1; i < values.size(); ++i)
        {
            best_score = max(best_score, values[i - 1] + i - 1);
            ans = max(ans, best_score + values[i] - i);
        }
        return ans;
    }
};