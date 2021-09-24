//
// Created by sajith on 9/24/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i: nums1)
        {
            mp[i]++;
        }

        for (int i: nums2)
        {
            if (mp[i] > 0)
            {
                ans.push_back(i);
                mp[i]--;
            }
        }

        return ans;
    }
};


int main()
{
    Solution solution;
    vector<int> v1 = {3, 1, 2};
    vector<int> v2 = {1, 1};

    solution.intersect(v1, v2);
    return 0;
}