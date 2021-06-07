//
// Created by sajith on 6/7/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    int myAtoi(string s)
    {
        int i = 0;
        int n = s.length();
        bool negative = false;

        while (s[i] == ' ')
        {
            i++;
        }

        if (s[i] == '-')
        {
            negative = true;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }

        /*
         * INT_MAX = 2147483647
         * INT_MIN = -2147483648
         */

        int res = 0;
        while (isDigit(s[i]) && i < n)
        {
            if (!negative)
            {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' >= 7))
                {
                    return INT_MAX;
                }

            }
            else
            {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' >= 8))
                {
                    return INT_MIN;
                }
            }

            res = res * 10 + (s[i] - '0');
            i++;
        }
        if (negative)
        {
            res = -1 * res;
        }
        return res;
    }
};


int main()
{
    Solution solution;
    cout << solution.myAtoi("42");
    return 0;
}