//
// Created by sajith on 7/12/22.
//

#include "base.h"

class Solution
{
    vector<int> sides;

    bool backtrack(size_t i, int side_sum, const vector<int> &matchsticks)
    {
        if (i == matchsticks.size()) return true;

        for (int j = 0; j < 4; ++j)
        {
            if (sides[j] + matchsticks[i] <= side_sum)
            {
                sides[j] += matchsticks[i];
                if (backtrack(i + 1, side_sum, matchsticks)) return true;

                sides[j] -= matchsticks[i];
            }
        }
        return false;
    }

public:
    bool makesquare(vector<int> &matchsticks)
    {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        sides.resize(4, 0);
        return backtrack(0, total / 4, matchsticks);
    }
};


int main()
{
    Solution solution;
    vector<int> v{1, 1, 2, 2, 2};
   cout<<boolalpha<<  solution.makesquare(v);

    return 0;
}