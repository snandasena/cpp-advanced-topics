//
// Created by sajith on 1/21/22.
//

#include "base.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        auto N = static_cast<int> (gas.size());
        int total_surplus = 0;
        int surplus = 0;
        int S = 0;

        for (int i = 0; i < N; ++i)
        {
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if (surplus < 0)
            {
                surplus = 0;
                S = i + 1;
            }
        }

        return (total_surplus >= 0) ? S : -1;
    }
};
