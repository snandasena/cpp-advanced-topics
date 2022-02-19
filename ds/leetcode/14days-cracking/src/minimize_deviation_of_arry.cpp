//
// Created by sajith on 2/19/22.
//

#include "base.h"

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        set<int> order_set;
        for (auto &i: nums)
        {
            if (i % 2 == 1) i *= 2;
            order_set.insert(i);
        }

        int diff = *order_set.rbegin()-*order_set.begin();
        int mx;
        while (*order_set.rbegin() % 2 == 0)
        {
            mx = *order_set.rbegin();
            order_set.erase(mx);
            order_set.insert(mx / 2);
            diff = min(*order_set.rbegin() - *order_set.begin(), diff);
        }
        return diff;
    }
};

int main()
{
    Solution sol;
    vector<int> v{2,10,8};
    cout<<sol.minimumDeviation(v)<<endl;
    return 0;
}