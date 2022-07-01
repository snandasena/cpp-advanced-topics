//
// Created by sajith on 6/30/22.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> is_prime(n, true);

        for (int i = 2; i * i < n; ++i)
        {
            if (!is_prime[i]) continue;

            for (int j = i * i; j < n; j += i)
            {
                is_prime[j] = false;
            }
        }

        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            if (is_prime[i])
            {
                ++ans;
            }
        }

        return ans;
    }
};