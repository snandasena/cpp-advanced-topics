//
// Created by sajith on 12/27/21.
//

#include "base.h"

class Solution
{
public:
    int findComplement(int num)
    {
        int res = 1;
        int n = num;
        while (n != 1)
        {
            n >>= 1;
            res <<= 1;
            res |= 1;
        }
        return res ^ num;
    }
};

int main()
{
    Solution sol;
    cout << sol.findComplement(5);
    return 0;
}