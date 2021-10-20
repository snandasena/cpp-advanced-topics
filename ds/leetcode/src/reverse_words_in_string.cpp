//
// Created by sajith on 10/20/21.
//

#include "base.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int i = 0, j;
        while (i < s.length())
        {
            while (i < s.length() && s[i] == ' ') ++i;
            if (i >= s.length()) break;
            j = i + 1;
            while (j < s.length() && s[j] != ' ') ++j;

            if (res.empty()) res = s.substr(i, j - i);
            else res = s.substr(i, j - i) + " " + res;
            i = j + 1;
        }
        return res;
    }
};