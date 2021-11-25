//
// Created by sajith on 11/25/21.
//

#include "base.h"


class Solution
{
public:
    int maxProduct2(vector<int> &nums)
    {
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0) swap(mn, mx);

            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            ans = max(ans, mx);
        }
        return ans;
    }

    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1) return nums[0];
        int mx = 0;
        int curr = 1;
        for (auto i = nums.begin(); i != nums.end(); ++i)
        {
            curr *= *i;
            mx = max(mx, curr);
            if (curr == 0) curr = 1;
        }

        curr = 1;
        for (auto i = nums.rbegin(); i != nums.rend(); ++i)
        {
            curr *= *i;
            mx = max(mx, curr);
            if (curr == 0) curr = 1;
        }

        return mx;
    }

};

int main()
{
    Solution solution;
    vector<int> v{2, 3, -2, 4};
    cout << solution.maxProduct(v) << endl;
    return 0;
}