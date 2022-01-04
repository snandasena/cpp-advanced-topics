//
// Created by sajith on 1/2/22.
//

#include "base.h"

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> v(60, 0);
        int res = 0;
        int curr;
        for (auto const &t: time)
        {
            curr = t % 60;
            if (curr == 0)
            {
                res += v[0];
            }
            else
            {
                res += v[60 - curr];
            }

            ++v[curr];
        }
        return res;

    }
};

int main()
{
    Solution sol;
    vector<int> v{30, 20, 150, 100, 40};
    cout << sol.numPairsDivisibleBy60(v) << endl;
}