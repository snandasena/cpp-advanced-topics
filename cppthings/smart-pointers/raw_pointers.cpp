//
// Created by sajith on 11/9/21.
//

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>

using namespace std;

using myobj = struct MyObject
{
    int x;
    int y;
};

void test_ptr()
{
    auto myObj2 = make_unique<MyObject>();
    myObj2->x = 10;
    myObj2->y = 10;
}


int main()
{
//    test_ptr();
    auto t = make_unique<myobj>(myobj{10, 20});
    char lastc = 0;
    string s = "big light in sky slated to appear in east";
    transform(s.begin(), s.end(), s.begin(), [&](const char &c)
    {
        const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : c;
        lastc = c;
        return r;
    });
    cout << s << endl;
    return 0;
}