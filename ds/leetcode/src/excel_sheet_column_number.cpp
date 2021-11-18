//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
public:
    int titleToNumber(string s)
    {
        int sum = 0;
        int mul = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            sum += ((s[i] - 64) * mul);
            mul *= 26;
        }
        return sum;
    }
};


int main()
{
    string s = "FXSHRXW";
    int sum = 0;
    int mul = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        sum += ((s[i] - 64) * mul);
        mul *= 26;
    }

    cout << sum << endl;
    return 0;
}