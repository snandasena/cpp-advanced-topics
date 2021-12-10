//
// Created by sajith on 12/9/21.
//

#include "base.h"

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        auto n = arr.size();
        queue<int> que;
        que.push(start);
        int curr;
        while (!que.empty())
        {
            curr = que.front();
            que.pop();

            if (arr[curr] == 0) return true;
            if (arr[curr] < 0) continue;

            if (curr + arr[curr] < n)
            {
                que.push(curr + arr[curr]);
            }

            if (curr - arr[curr] >= 0)
            {
                que.push(curr - arr[curr]);
            }
            arr[curr] = -arr[curr];
        }
        return false;
    }
};