//
// Created by sajith on 6/28/22.
//

#include "base.h"

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> v(26, 0);
        for (const auto &item: s)
        {
            ++v[item - 'a'];
        }

        sort(v.begin(), v.end(), greater<>());
        int ans = 0;
        int max_allowed = s.length();
        for (int i = 0; i < 26 && v[i] > 0; ++i)
        {
            if (v[i] > max_allowed)
            {
                ans += v[i] - max_allowed;
                v[i] = max_allowed;
            }
            max_allowed = max(0, v[i] - 1);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.minDeletions("aac") << endl;
    return 0;
}