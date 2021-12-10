//
// Created by sajith on 12/10/21.
//

#include "base.h"

class Solution
{
    unsigned int const MOD = 1'000'000'007;
public:
    int numTilings(int n)
    {
        unsigned int currBaseCount = 1;
        unsigned int prevBaseCount = 1;
        unsigned int nextBaseCount;

        unsigned int currExtraCount = 1;
        unsigned int prevExtraCount = 0;
        unsigned int nextExtraCount;

        for (int i = 2; i <= n; ++i)
        {
            nextBaseCount = (currBaseCount + prevBaseCount + prevExtraCount * 2) % MOD;

            nextExtraCount = (currExtraCount + currBaseCount) % MOD;

            prevBaseCount = currBaseCount;
            prevExtraCount = currExtraCount;

            currBaseCount = nextBaseCount;
            currExtraCount = nextExtraCount;

        }
        return static_cast<int>(currBaseCount);
    }
};