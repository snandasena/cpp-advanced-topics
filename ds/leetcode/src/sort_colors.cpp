//
// Created by sajith on 10/27/21.
//

#include "base.h"

class Solution
{
public:
    void sortColors2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    }

    void sortColors(vector<int> &nums)
    {
        vector<int> arr(3, 0);

        for (int &i: nums)
        {
            ++arr[i];
        }

        int k = 0;
        for (int &i: nums)
        {
            if (k < arr[0])
            {
                i = 0;
            } else if (k < arr[0] + arr[1])
            {
                i = 1;
            } else
            {
                i = 2;
            }
        }
    }


};