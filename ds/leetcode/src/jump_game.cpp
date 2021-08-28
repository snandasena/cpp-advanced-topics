//
// Created by sajith on 8/28/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int pos = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == 0 && pos == i)
            {
                return false;
            }
            pos = max(pos, nums[i] + i);
        }
        return pos >= nums.size() - 1;
    }
};