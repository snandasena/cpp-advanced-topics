//
// Created by sajith on 9/25/21.
//

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'substringCalculator' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING s as parameter.
 */

long substringCalculator(string s)
{

    unordered_set<string> us;
    for (int i = 0; i < s.size(); ++i)
    {
        string str;
        for (int j = i; j < s.size(); ++j)
        {

            str += s[j];
            us.insert(str);
        }
    }

    return static_cast<int> (us.size());
}

int main()
{
    string s = "sfsvsdf";

    stoi(s);
    return 0;
}
