//
// Created by sajith on 9/12/21.
//


#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> maxleft(height.size(), 0);
        vector<int> maxright(height.size(), 0);

        int mxleft = 0;
        for (int i = 1; i < height.size(); ++i)
        {
            mxleft = max(height[i - 1], mxleft);
            maxleft[i] = mxleft;
        }

        int mxright = 0;
        for (int i = height.size() - 2; i >= 0; i--)
        {
            mxright = max(height[i + 1], mxright);
            maxright[i] = mxright;
        }

        int ans = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            ans += max(min(maxright[i], maxleft[i]) - height[i], 0);
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << solution.trap(height);

    return 0;
}