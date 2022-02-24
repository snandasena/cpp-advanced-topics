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
        int a;
        int b;
        int ans = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            a = s[i] - '0';
            if (a != 0) ++ans;
            b = s[i + 1] - '0';

            a = a + b * 10;
            if (a > 0 && a< 27) ++ans;
        }

        return ans;
    }
};


int main()
{
    Solution solution;
    cout << solution.numDecodings("220") << endl;
    return 0;
}