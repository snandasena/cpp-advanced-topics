//
// Created by sajith on 10/10/21.
//

#include "base.h"

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            int bit = (1 << i);
            if ((left & bit) != (right & bit))
            {
                break;
            } else
            {
                ans |= left&bit;
            }
        }
        return ans;
    }
};