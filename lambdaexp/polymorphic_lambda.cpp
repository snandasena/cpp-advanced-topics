//
// Created by sajith on 7/15/21.
//

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{

    auto fp = [](const auto &n) -> auto
    {
        return n * 4;
    };

    int n = 10;
    auto x = fp(n);

    cout << "value of x: " << x << " type of x: " << typeid(x).name() << "\n";

    return 0;
}