//
// Created by sajith on 2/18/22.
//

#include "base.h"

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        if (n == 0) return ans;
        ans.push_back(1);

        int curr = 1;
        for (int i = 2; i <= n; ++i)
        {
            curr <<= 1;
            for (int j = ans.size() - 1; j >= 0; --j)
            {
                ans.push_back(curr + ans[j]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    auto  ans = solution.grayCode(2);
    return 0;
}
