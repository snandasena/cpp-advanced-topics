//
// Created by sajith on 1/27/22.
//

#include "base.h"

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int maxx = 0, mask = 0;
        auto n = nums.size();
        set<int> se;
        for (int i = 30; i >= 0; i--)
        {
            // set the i'th bit in mask
            // like 100000, 110000, 111000..
            mask |= (1 << i);
            for (int i = 0; i < n; ++i)
            {
                // Just keep the prefix till
                // i'th bit neglecting all
                // the bit's after i'th bit
                se.insert(nums[i] & mask);
            }

            int newMaxx = maxx | (1 << i);
            for (int prefix : se)
            {
                // find two pair in set
                // such that a^b = newMaxx
                // which is the highest
                // possible bit can be obtained
                if (se.count(newMaxx ^ prefix))
                {
                    maxx = newMaxx;
                    break;
                }
            }

            // clear the set for next
            // iteration
            se.clear();
        }

        return maxx;
    }
};

int main()
{
    Solution sol;
    vector<int> v{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};

    cout << sol.findMaximumXOR(v) << endl;
    return 0;
}