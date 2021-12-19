//
// Created by sajith on 12/19/21.
//

#include "base.h"

class Solution
{
public:

    string decodeString(string &str, int &i)
    {
        string result;
        while (i < str.length() && str[i] != ']')
        {
            if (isdigit(str[i]))
            {
                int k = 0;
                while (i < str.length() && isdigit(str[i]))
                {
                    k = k * 10 + str[i++] - '0';
                }
                i++;
                string r = decodeString(str, i);
                while (k-- > 0)
                {
                    result += r;
                }
                ++i;
            }
            else
            {
                result += str[i++];
            }
        }
        return result;
    }

    string decodeString(string s)
    {
        int i = 0;
        return decodeString(s, i);
    }
};


int main()
{
    Solution solution;
    cout << solution.decodeString("3[a]2[bc]") << endl;
    return 0;
}