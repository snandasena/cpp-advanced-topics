//
// Created by sajith on 6/12/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 and nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                if (l > i + 1 and nums[l] == nums[l - 1])
                {
                    ++l;
                    continue;
                }

                int currsum = nums[i] + nums[l] + nums[r];

                if (currsum == 0)
                {
                    res.push_back({nums[i], nums[l++], nums[r--]});
                }
                else if (currsum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }


        }

        return res;
    }
};


int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};

    Solution solution;

    auto res = solution.threeSum(v);

    for (auto t: res)
    {
        cout << t[0] << " " << t[1] << " " << t[2] << endl;
    }


    return 0;
}