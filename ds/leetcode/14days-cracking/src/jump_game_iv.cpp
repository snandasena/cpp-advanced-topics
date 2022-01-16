//
// Created by sajith on 1/15/22.
//

#include "base.h"


class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        auto n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
        {
            mp[arr[i]].push_back(i);
        }

        queue<int> que;
        que.push(0);
        int ans = 0;
        while (!que.empty())
        {
            ++ans;
            auto sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                int x = que.front();
                que.pop();

                if (x + 1 < n && mp.count(arr[x + 1]))
                {
                    if (x + 1 == n - 1) return ans;
                    que.push(x + 1);
                }

                if (x - 1 >= 0 && mp.count(arr[x - 1]))
                {
                    que.push(x - 1);
                }

                if (mp.count(arr[x]))
                {
                    for (auto const &a: mp[arr[x]])
                    {
                        if (a == n - 1) return ans;
                        que.push(a);
                    }
                }

                mp.erase(arr[x]);
            }
        }

        return ans;
    }
};