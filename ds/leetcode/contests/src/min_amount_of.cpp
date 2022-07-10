//
// Created by sajith on 7/10/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        int ans = 0;
        while (*max_element(amount.begin(), amount.end()) != 0)
        {
            sort(amount.begin(), amount.end(), greater<>());
            --amount[0];
            --amount[1];
            ++ans;
        }
        return ans;
    }
};

int main()
{

    Solution solution;

    vector<int> v{0,0,0};
    cout << solution.fillCups(v);
}