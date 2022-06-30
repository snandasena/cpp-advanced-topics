//
// Created by sajith on 6/30/22.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        auto mid =
                nums.size() % 2 == 0 ? (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2 : nums[nums.size() / 2];
        int ans = 0;
        for (const auto &item: nums)
        {
            ans += abs(item - mid);
        }
        return ans;
    }
};

int main()
{
    // 1, 2, 9, 10
    // 2,9, 2, 9  // 1 + 8
    // 2, 5, 2, 5
    //
    return 0;
}