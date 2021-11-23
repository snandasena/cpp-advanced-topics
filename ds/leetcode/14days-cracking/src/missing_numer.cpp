//
// Created by sajith on 11/23/21.
//

class Solution
{
public:
    int missingNumber1(vector<int> &nums)
    {
        auto n = nums.size();
        int total = (n + 1) * n / 2;
        for (auto &i: nums)
        {
            total -= i;
        }
        return total;
    }

    int missingNumber(vector<int> &nums)
    {
        int ans = 0;
        auto n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            ans ^= i;
            ans ^= nums[i];
        }
        return ans ^ n;
    }
};