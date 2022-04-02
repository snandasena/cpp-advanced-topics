//
// Created by sajith on 4/2/22.
//

#include "base.h"

class Solution
{
    bool IsPalindrome(const string &s, size_t l, size_t r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        auto r = s.size() - 1;
        size_t l = 0;

        while (l < r)
        {
            if (s[l] != s[r])
            {
                return (IsPalindrome(s, l, r - 1) || IsPalindrome(s, l + 1, r));
            }
            ++l;
            --r;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s{"atbbga"};
    cout << boolalpha << solution.validPalindrome(s) << endl;
    return 0;
}