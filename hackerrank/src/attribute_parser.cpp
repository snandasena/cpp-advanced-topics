//
// Created by sajith on 11/4/22.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Attribute
{
    string name;
    string value;
};

struct Tag
{
    string name;
    vector <pair<string, string>> attrs;
    vector <Tag> children;
};


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str{"<tag3 another= \"another\" final=\"final\" final2=\"final2value\">"};

    string tag;
    string attr;
    int i = 1;
    while (i < str.size() && str[i] != ' ')
    {
        tag += str[i];
        ++i;
    }
    ++i;
    cout << tag << endl;

    string final_value;
    string final_attr;

    bool value_type = false;
    while (i < str.size())
    {
        if (str[i] != '=' && str[i] != ' ')
        {
            attr += str[i];
        }
        else if(str[i] !='>')
        {
            if (!attr.empty())
            {
                if (!value_type)
                {
                    cout << "attr = " << attr << endl;
                    value_type = true;
                }
                else
                {
                    cout << "value = " << attr << endl;
                    value_type = false;
                }
            }
            attr.clear();
        }
        ++i;
    }

    return 0;
}
