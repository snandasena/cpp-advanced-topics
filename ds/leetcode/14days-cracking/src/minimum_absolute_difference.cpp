//
// Created by sajith on 12/20/21.
//


#include "base.h"

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {

        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int mn = 100000000;
        int diff;
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            diff = arr[i + 1] - arr[i];
            if (diff == mn)
            {
                ans.push_back({arr[i], arr[i + 1]});
            }
            else if (diff < mn)
            {
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
                mn = diff;
            }
        }

        return ans;
    }
};

