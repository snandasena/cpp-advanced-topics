//
// Created by sajith on 1/16/22.
//

#include "base.h"

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        auto n = static_cast<int> (seats.size());
        int ans = 0;
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            if (seats[i] == 1)
            {
                k = 0;
            }
            else
            {
                ++k;
                ans = max(ans, (k + 1) / 2);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (seats[i] == 1)
            {
                ans = max(ans, i);
                break;
            }
        }

        for (int i = n - 1; i >= 0; --i)
        {
            if (seats[i] == 1)
            {
                ans = max(ans, n - i - 1);
                break;
            }
        }

        return ans;
    }
};


int main()
{
    vector<int> v{1,0,0,0,1,0,1};
    Solution sol;
    cout << sol.maxDistToClosest(v) << endl;

    return 0;
}