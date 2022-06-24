//
// Created by sajith on 6/24/22.
//
#include "base.h"

class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        priority_queue<int> pq;
        long long sum = 0;
        for (const auto &item: target)
        {
            pq.push(item);
            sum += item;
        }
        int old;
        while (pq.top() != 1)
        {
            sum -= pq.top();
            if (sum == 0 || sum >= pq.top()) return false;
            old = pq.top() % sum;
            if (sum != 1 && old == 0) return false;
            pq.pop();
            pq.push(old);
            sum += old;
        }
        return true;
    }
};