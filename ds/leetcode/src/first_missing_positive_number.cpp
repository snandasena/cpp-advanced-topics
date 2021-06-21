//
// Created by sajith on 6/21/21.
//

#include <bits/stdc++.h>

using namespace std;


class Solution
{

public:
    int firstMissingPositive(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                ++i;
            }
        }

        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != (j + 1))
            {
                return j + 1;
            }
        }

        return nums.size() + 1;
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 2, 0};
    cout << solution.firstMissingPositive(nums) << endl;

    nums.clear();
    nums = {3, 4, -1, 1};
    cout << solution.firstMissingPositive(nums) << endl;

    nums.clear();
    nums = {7,8,9,11,12};
    cout << solution.firstMissingPositive(nums) << endl;

    return 0;
}