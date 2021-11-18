//
// Created by sajith on 11/18/21.
//

#include "base.h"

class Solution
{
public:
    string convertToTitle(int num)
    {
        string s;
        while (num)
        {
            num--;
            int k = num % 26;
            s = char('A' + k) + s;
            num /= 26;
        }
        return s;
    }
};

int main()
{
    int num = 2147483647;
    string s;
    while (num)
    {
        num--;
        int k = num % 26;
        cout << char('A' + k) << "";
        s = char('A' + k) + s;
        num /= 26;
    }

    cout << endl << s << endl;
}