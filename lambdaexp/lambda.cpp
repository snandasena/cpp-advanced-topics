#include <iostream>

using namespace std;

int main()
{
    int x = 42;

    auto myLamb = [x]() // here x is a capture variable
    {
        cout << "Hello from a lambda expression x= " << x << "\n";
    };

    auto myLamb2 = [&x]() // lvalue reference capture value
    {
        cout << "Hello from a lambda expression 2 x= " << x << "\n";
    };
    auto myLamb3 = [x]() mutable
    {
        ++x;
        cout << "Hello from a lambda expression 2 x= " << x << "\n";
        return x;
    };

    myLamb();
    x = myLamb3();
    cout << "x= " << x << "\n";
    x = 7;
    myLamb2();
    return 0;
}