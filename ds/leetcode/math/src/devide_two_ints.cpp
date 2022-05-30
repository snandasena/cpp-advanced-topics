//
// Created by sajith on 5/30/22.
//

#include "base.h"

class Solution
{
    using LL = long int;
    static constexpr LL M = (LL) INT_MAX;
    static constexpr LL N = (LL) INT_MIN;

public:
    int divide(int dividend, int divisor)
    {
        auto ans = (LL) dividend / (LL)divisor;
        if (ans > M) return M;
        else if (ans < N) return N;
        else return ans;
    }
};
