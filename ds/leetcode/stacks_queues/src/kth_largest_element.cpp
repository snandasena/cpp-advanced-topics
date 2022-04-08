
//
// Created by sajith on 4/8/22.
//

#include "base.h"

class KthLargest
{
    int _k;
    priority_queue<int, vector<int>, greater<>> _pq;
public:
    KthLargest(int k, vector<int> &nums)
    {
        _k = k;
        for (const auto &item: nums)
        {
            _pq.push(item);
        }

        while (_pq.size() > k)
        {
            _pq.pop();
        }

    }

    int add(int val)
    {
        _pq.push(val);
        while (_pq.size() > _k)
        {
            _pq.pop();
        }
        return _pq.top();
    }
};
