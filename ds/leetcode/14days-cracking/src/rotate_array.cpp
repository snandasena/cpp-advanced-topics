//
// Created by sajith on 9/21/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> rotate1(vector<int> &nums, int k)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i)
        {
            ans.push_back(nums[(i + k + 1) % nums.size()]);
        }

        return ans;
    }

    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};

    Solution solution;
    vector<int> res = solution.rotate1(v, 3);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}