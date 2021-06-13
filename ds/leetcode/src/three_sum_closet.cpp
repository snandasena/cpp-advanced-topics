//
// Created by sajith on 6/13/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int sz = nums.size();

        for (int i = 0; i < sz and diff != 0; ++i)
        {
            int lo = i + 1, hi = sz - 1;
            while (lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff))
                {
                    diff = target - sum;
                }

                if (sum < target)
                {
                    ++lo;
                }
                else
                {
                    --hi;
                }
            }
        }
        return target - diff;
    }
};

int main()
{

    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution solution;
    cout<<solution.threeSumClosest(nums, target)<<endl;
    return 0;
}