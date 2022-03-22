//
// Created by sajith on 3/22/22.
//

#include "base.h"

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        char ans[n];
        int curr;
        for (int i = n - 1; i >= 0; --i)
        {
            curr = min(26, k - i);
            ans[i] = ('a' + curr - 1);
            k -= curr;
        }
        return string(ans, ans + n);
    }
};