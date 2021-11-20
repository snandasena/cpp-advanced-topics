//
// Created by sajith on 11/20/21.
//

#include "base.h"


class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        uint32_t mask1;
        uint32_t mask2;
        for (int i = 0; i < 32; ++i)
        {
            mask1 = 1 << i;
            if ((mask1 & n) == 0) continue;
            else
            {
                mask2 = 1 << (32 - i - 1);
                res |= mask2;
            }
        }
        return res;
    }
};


int main()
{
    Solution solution;
    cout<<solution.reverseBits(43261596)<<endl;
    return 0;
}