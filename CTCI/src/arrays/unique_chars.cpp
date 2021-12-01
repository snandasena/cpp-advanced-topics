//
// Created by sajith on 11/29/21.
//

#include "../base.h"


bool is_unique_chars(string const &str)
{
    if (str.length() < 128) return false;
    vector<bool> charv(128, false);
    for (auto c: str)
    {
        if (charv[int(c)])
        {
            return false;
        }
        charv[int(c)] = true;
    }
    return true;
}

bool check_permutations(string const &str1, string const &str2)
{
    vector<int> v(str1.length(), 0);
    for (auto ch: str1)
    {
        ++v[int(ch - 'a')];
    }

    for (auto ch: str2)
    {
        if (v[int(ch - 'a')] == 0) return false;
    }

    return true;
}

string URLify(string &str, int truelength)
{
    int spaceCount = 0;
    int index;
    int i;
    for (i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ') ++spaceCount;
    }

    index = truelength + spaceCount * 2;
    if (truelength < str.length())
    {
        str[truelength] = '\0';
    }

    for (i = truelength - 1; i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        }
        else
        {
            str[index - 1] = str[i];
            --index;
        }
    }

    return str;
}

int main()
{
    string str = "Mr John Smith";
    cout << URLify(str, 13) << endl;
    return 0;
}