//
// Created by sajith on 11/15/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        auto sz = static_cast<int>(nums.size());
        if (sz <= 1) return nums;
        vector<vector<int>> res(sz, vector<int>());
        sort(nums.begin(), nums.end());

        int maxlen = 1;
        int mxidx = 0;
        int _mx_idx;
        int _max;
        int j;

        for (int i = sz - 1; i >= 0; i--)
        {
            res[i].push_back(nums[i]);
            j = i + 1;
            _max = 0;
            _mx_idx = i;

            while (j < sz)
            {
                if (nums[j] % nums[i] == 0 && res[j].size() > _max)
                {
                    _max = static_cast<int>(res[j].size());
                    _mx_idx = j;
                }
                j++;
            }

            if (_mx_idx != i)
            {
                res[i].insert(res[i].end(), res[_mx_idx].begin(), res[_mx_idx].end());
                if (_max + 1 > maxlen)
                {
                    maxlen = _max + 1;
                    mxidx = i;
                }
            }
        }
        return res[mxidx];
    }
};

int main()
{
    vector<int> v = {3, 4, 16, 8};
    Solution solution;
    vector<int> res = solution.largestDivisibleSubset(v);
    return 0;
}


// eranga@beverleyint.co.nz