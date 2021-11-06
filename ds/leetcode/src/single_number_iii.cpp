//
// Created by sajith on 11/6/21.
//

#include "base.h"

using li = long int;

class Solution
{
public:
    vector<int> singleNumber1(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (const int &i: nums)
        {
            mp[i]++;
        }

        for (auto &p: mp)
        {
            if (p.second == 1) ans.push_back(p.first);
        }

        return ans;
    }

    vector<int> singleNumber(vector<int> &nums)
    {
        li xr = 0;
        for (const int &i: nums) xr ^= i;
        xr = xr & (-xr);
        int x =0, y = 0;

        for (const int &i: nums)
        {
            if ((xr & i) == 0) x ^= i;
            else y ^= i;
        }
        return {x, y};
    }
};

int main()
{
//    Solution solution;
/*
 * 3 - 011
 * 5 - 101
 * XOR -  110 -> 6
 * -6 - ( 0110 -> 1001 -> 1010)
 *
 * 6 & ~6 - 0110 & 1010 -> 0010
 */
    vector<int> nums = {1, 2, 1, 3, 2, 5};

    int xr = 0;
    for (int num : nums)
    {
        xr = xr ^ num;
    }

//    cout << xr << "\n";
    int n = xr & (-xr);
//    cout << n << "\n";

    int x = 0;
    int y = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if ((n & nums[i]) == 0)
        {
            x ^= nums[i];
            cout << "x = " << x << "\n";
        }
        else
        {
            y ^= nums[i];
            cout << "y = " << y << "\n";
        }
    }

    cout << x << " " << y << "\n";

    return 0;
}