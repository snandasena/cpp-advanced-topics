//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string str;
        for (char const &c: s)
        {
            if (isdigit(c)) str += c;
            else if (c >= 'a' && c <= 'z') str += c;
        }
        int len = str.length();
        for (int i = 0; i < len / 2; ++i)
        {
            if (str[i] != str[len - 1 - i]) return false;
        }
        return true;
    }
};
