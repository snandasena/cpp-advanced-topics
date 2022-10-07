//
// Created by sajith on 10/7/22.
//

#include <bits/stdc++.h>

using namespace std;

struct XMLTag
{
    string name;
    string value;
    vector<XMLTag> child_elements;
    int intend_size = 2;

    XMLTag() = default;

    XMLTag(const string &&_name, const string &&_value) : name{_name}, value{_value}
    {}

    string str(int intend = 0) const
    {
        string i(intend * intend_size, ' ');

        ostringstream oss;
        oss << i << "<" << name << ">";
        if (!value.empty())
        {
            oss << value;
        }

        for (const auto &ele: child_elements)
        {
            oss << ele.str(intend + 1);
        }

        oss << i << "</" << name << ">";
        return oss.str();
    }

};


int main()
{
    XMLTag root{"root", ""};
    XMLTag child{"child", "10"};
    root.child_elements.push_back(child);
    cout << root.str();
}