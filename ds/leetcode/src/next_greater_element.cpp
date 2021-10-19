//
// Created by sajith on 10/19/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        bool found;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); ++i)
        {
            mp[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); ++i)
        {
            found = false;
            for (int j = mp[nums1[i]]; j < nums2.size(); ++j)
            {
                if (nums1[i] < nums2[j])
                {
                    ans.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }

            if (!found) ans.push_back(-1);
        }
        return ans;
    }
};