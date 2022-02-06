//
// Created by sajith on 2/4/22.
//
#include "base.h"

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int mxlen = 0;
        int cnt = 0;
        auto N = static_cast<int>(nums.size());
        for (int i = 0; i < N; ++i)
        {
            cnt = cnt + (nums[i] == 1 ? 1 : -1);
            if (mp.count(cnt))
            {
                mxlen = max(mxlen, i - mp[cnt]);
            }
            else
            {
                mp[cnt] = i;
            }
        }
        return mxlen;
    }
};

int main()
{
    Solution sol;
    vector<int> v{0, 1};
    cout << sol.findMaxLength(v) << endl;

    return 0;
}