//
// Created by sajith on 11/9/21.
//

#include <iostream>
#include <memory>

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
    return 0;
}