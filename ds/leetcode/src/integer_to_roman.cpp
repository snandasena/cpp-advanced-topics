//
// Created by sajith on 6/9/21.
//


#include <bits/stdc++.h>

using namespace std;
int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string text[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        for (int i = 0; i < 13; ++i)
        {
            while (nums[i] <= num)
            {
                res += text[i];
                num -= nums[i];
            }
        }

        return res;
    }

};


int main()
{
    Solution solution;
    cout << solution.intToRoman(3999) << endl;
    return 0;
}