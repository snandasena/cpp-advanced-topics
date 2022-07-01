//
// Created by sajith on 7/1/22.
//


#include <bits/stdc++.h>

using namespace std;

struct Compare
{

    bool operator()(int a, int b)
    {
        auto aStr = to_string(a);
        auto bStr = to_string(b);
        return aStr + bStr > bStr + aStr;
    }
};

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        auto mx = *max_element(nums.begin(), nums.end());
        if (mx == 0) return "0";
        sort(nums.begin(), nums.end(), Compare());

        string ans{};
        for (const auto &item: nums)
        {
            ans += to_string(item);
        }
        return ans;
    }
};

int main()
{

    return 0;
}