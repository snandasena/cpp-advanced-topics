//
// Created by sajith on 4/6/22.
//

#include "base.h"

class Solution
{
    const int MOD = 1e9 + 7;
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        auto N = arr.size();
        unordered_map<int, int> mp;
        int need;
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                need = target - arr[i] - arr[j];
                cnt += mp[need];
            }
            cnt %= MOD;
            mp[arr[i]]++;
        }
        return cnt % MOD;
    }
};