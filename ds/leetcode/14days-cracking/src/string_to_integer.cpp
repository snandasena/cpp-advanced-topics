//
// Created by sajith on 1/14/22.
//

#include "base.h"

class Solution
{
public:
    int myAtoi(string s)
    {
        int ans = 0;
        string str;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                while (i < s.size() && isdigit(s[i]))
                {
                    str += s[i];
                    ++i;
                }
                break;
            }
            else if (i < s.size() - 1 && s[i] == '-' && isdigit(s[i + 1]))
            {
                str = '-' + str;
            }
        }
        return stoi(str);
    }
};

int main()
{
    Solution sol;
    string s{"-00004193 with words"};

    cout << sol.myAtoi(s) << endl;
    return 0;
}