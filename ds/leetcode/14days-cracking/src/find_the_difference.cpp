//
// Created by sajith on 11/27/21.
//

#include "base.h"

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int x = 0;
        for (auto c: s)
        {
            x ^= int(c);
        }

        for (auto c: t)
        {
            x ^= int(c);
        }

        return char(x);
    }
};

int main()
{
    Solution solution;
    cout << solution.findTheDifference("abcd", "abcde");

    bitset<32> x(7);
    cout<< x.count()<< endl;

    return 0;
}