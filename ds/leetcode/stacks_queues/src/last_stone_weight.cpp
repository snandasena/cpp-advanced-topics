//
// Created by sajith on 4/7/22.
//

#include "base.h"

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        int x;
        int y;
        while (pq.size() > 1)
        {
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();

            if (x != y)
            {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    Solution solution;
    vector<int> v{1, 2, 3};
    cout << solution.lastStoneWeight(v) << endl;
    return 0;
}