//
// Created by sajith on 11/16/21.
//

#include "base.h"

class Solution1
{
public:
    int findKthNumber(int m, int n, int k)
    {
        auto comp = [](pair<int, int> const &p1, pair<int, int> const &p2)
        {
            return p1.first > p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (int i = 1; i <= m; ++i)
        {
            pq.push({i, i});
        }

        pair<int, int> p;
        int next;
        for (int i = 0; i < k; ++i)
        {
            p = pq.top();
            pq.pop();
            next = p.first + p.second;
            if (next <= p.second * n)
            {
                pq.push({next, p.second});
            }
        }
        return p.first;
    }
};


class Solution
{
public:
    bool helper(int x, int m, int n, int k)
    {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
        {
            cnt += min(x / i, n);
        }
        return cnt >= k;
    }

    int findKthNumber(int m, int n, int k)
    {
        int lo = 1;
        int hi = m * n;
        int mid;
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            if (!helper(mid, m, n, k)) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

int main()
{
    Solution solution;
    cout << solution.findKthNumber(9895, 28405, 100787757) << endl;
    return 0;
}