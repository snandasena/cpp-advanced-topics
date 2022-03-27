//
// Created by sajith on 3/27/22.
//

#include "base.h"

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> ans;
        int cnt;
        for (int i = 0; i < mat.size(); ++i)
        {
            cnt = 0;
            for (int j = 0; j < mat[i].size(); ++j)
            {
                if (mat[i][j] == 1) ++cnt;
                else break;
            }

            ans.emplace_back(i, cnt);
        }

        sort(ans.begin(), ans.end(), [](pair<int, int> &p1, pair<int, int> &p2)
        {
            if (p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        });

        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(ans[i].first);
        }
        return res;
    }
};


