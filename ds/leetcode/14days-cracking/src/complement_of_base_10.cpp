//
// Created by sajith on 1/4/22.
//

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        if (n == 0) return 1;
        int a = n;
        int j = 0;
        while (a > 0)
        {
            a >>= 1;
            n ^= (1 << j);
            ++j;
        }
        return n;
    }
};