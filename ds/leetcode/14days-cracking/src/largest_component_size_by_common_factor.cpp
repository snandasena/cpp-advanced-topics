
//
// Created by sajith on 11/23/21.
//

#include "base.h"

class Solution
{
    vector<int> parent;

    int _find(int x)
    {
        if (parent[x] == -1)
        {
            return x;
        }
        parent[x] = _find(parent[x]);
        return parent[x];
    }

    void _union(int x, int y)
    {
        int xp = _find(x);
        int yp = _find(y);
        if (xp != yp)
        {
            parent[yp] = xp;
        }
    }


public:
    Solution()
    {
        parent.resize(100001, -1);
    }

    int largestComponentSize(vector<int> &nums)
    {
        for (auto x: nums)
        {
            for (int i = 2; i <= sqrt(x); ++i)
            {
                if (x % i == 0)
                {
                    _union(i, x);
                    _union(x, x / i);
                }
            }
        }

        int cnt = 0;
        unordered_map<int, int> cache;
        for (auto x: nums)
        {
            int xp = _find(x);
            cnt = max(cnt, 1 + cache[xp]);
            cache[xp] += 1;
        }
        return cnt;
    }
};

int main()
{
    vector<int> v{4, 6, 15, 35};
    Solution solution;
    solution.largestComponentSize(v);
    return 0;
}