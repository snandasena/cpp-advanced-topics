//
// Created by sajith on 6/22/22.
//

#include "base.h"

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, less<>> pq;
        for (const auto &item : nums)
            pq.push(item);

        while (k-- != 1)
        {
            pq.pop();
        }

        return pq.top();
    }
};