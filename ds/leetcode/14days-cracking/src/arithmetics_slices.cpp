//
// Created by sajith on 2/6/22.
//

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3) return 0;
        auto N = static_cast<int>(nums.size());
        int ans = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int count = 0; i + 2 < N && nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]; ++i)
            {
                ++count;
                ans += count;
            }
        }
        return ans;
    }
};