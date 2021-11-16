//
// Created by sajith on 11/16/21.
//

#include <bits/stdc++.h>

using namespace std;

struct Widget
{
    int x;
    string y;
    char *z;

    ~Widget()
    {
        cout << "Destructor called\n";
    }
};

int main()
{
    int x = 5;
    try
    {
//        auto *widget = new Widget{10, "widget string", "widget cahr *"};
        auto widget = make_unique<Widget>(Widget{10, "widget string", "widget cahr *"});
        if (x < 10)
        {
            throw runtime_error{"Error has beed throwed\n"};
        }
//        delete widget;
    } catch (exception const &e)
    {
        cout << "ERROR: " << e.what();
    }

    return 0;
}