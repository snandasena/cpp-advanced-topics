//
// Created by sajith on 7/4/22.
//


#include "base.h"

// : 1 0 2
//-> 2 1 2

// : 1 2 2
//-> 1 2 1

class Solution
{
public:

    int candy(vector<int> &ratings)
    {
        vector<int> v1(ratings.size(), 1);
        vector<int> v2(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                v1[i] = v1[i - 1] + 1;
            }
        }


        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                v2[i] = v2[i + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < v1.size(); ++i)
        {
            ans += max(v1[i], v2[i]);
        }

        return ans;
    }
};