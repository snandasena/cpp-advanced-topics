//
// Created by sajith on 8/13/21.
//
#include <bits/stdc++.h>

using namespace std;

int sol(vector<int> &v)
{
    vector<int> dp(v.size());
    for (auto &i: v)
    {
        if (i > 0)
        {
            dp[i]++;
        }
    }
    for (int i = 1; i < v.size(); ++i)
    {
        if (dp[i] == 0)
        {
            return i;
        }
    }
    return dp.size() + 1;
}

int main()
{
    // 1, 3, 6, 4, 1, 2
    vector<int> v = {1, 3, 6, 4, 1, 2};

    cout << sol(v) << endl;
    v.clear();
    v = {1, 2, 3};
    cout << sol(v) << endl;
    v.clear();
    v = {-1, -3, -5, 0};
    cout<<sol(v)<<endl;
    return 0;
}
