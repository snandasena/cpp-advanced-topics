//
// Created by sajith on 2/21/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        auto N = static_cast<int >(s.size());
        vector<int> dp(N, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        int a;
        int b;
        for (int i = 1; i < N; ++i)
        {
            a = s[i] - '0';
            b = (10 * (s[i - 1] - '0')) + a;
            if (a >= 1)
            {
                dp[i] += dp[i - 1];
            }
            if (b >= 10 && b <= 26)
            {
                dp[i] += i >= 2 ? dp[i - 2] : 1;
            }
        }
        return dp[N - 1];
    }
};


int main()
{
    Solution solution;
    cout << solution.numDecodings("220") << endl;
    return 0;
}