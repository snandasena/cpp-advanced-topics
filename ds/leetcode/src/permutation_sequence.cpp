//
// Created by sajith on 9/18/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        vector<int> facts(n+1,1);
        for (int i = 1; i <= n; ++i)
        {
            facts[i] = facts[i - 1] * i;
            nums.push_back(i);
        }
        string res;
        k--;
        while (n > 0)
        {
            res += to_string(nums[k / facts[n - 1]]);
            nums.erase(nums.begin() + (k / facts[n - 1]));
            k %= facts[n - 1];
            n--;
        }
        return res;
    }
};
