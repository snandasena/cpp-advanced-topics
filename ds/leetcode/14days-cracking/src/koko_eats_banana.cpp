//
// Created by sajith on 1/20/22.
//


#include "base.h"

class Solution
{
public:
    int minEatingSpeed(vector<int> &P, int h)
    {
        sort(P.begin(), P.end());
        int mx = *max_element(P.begin(), P.end());
        int k = 1;
        int T;
        int mid;
        while (k < mx)
        {
            T = 0;
            mid = k + (mx - k) / 2;
            for (auto const &i: P)
            {
                T += i / mid + (i % mid == 0 ? 0 : 1);
            }

            if (T <= h)
            {
                mx = mid;
            }
            else
            {
                k = mid + 1;
            }
        }
        return mx;
    }
};

int main()
{
    Solution sol;
    vector<int> v{3, 6, 7, 11};
    int h = 8;
    cout << sol.minEatingSpeed(v, h);

    return 0;
}


