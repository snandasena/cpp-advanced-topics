#include <iostream>

using namespace std;

int main()
{
    int x = 42;

    auto myLamb = [x]()
    {
        cout << "Hello from a lambda expression "<<x <<"\n";
    };

    x = 7;
    myLamb();
    return 0;
}