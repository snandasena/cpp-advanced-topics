//
// Created by sajith on 7/5/22.
//


#include "base.h"

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        sort(special.begin(), special.end());

        int ans = special[0] - bottom;
        auto i = 0;
        for (; i < special.size() - 1; ++i)
        {
            ans = max(ans, special[i + 1] - special[i] - 1);
        }

        ans = max(ans, top - special[i]);
        return ans;
    }
};

int main()
{
    Solution solution;
    /*
     * 28
50
[35,48]
     */

    vector<int> v{35, 48};
    cout << solution.maxConsecutive(28, 50, v);
    return 0;
}