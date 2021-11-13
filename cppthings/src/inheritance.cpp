//
// Created by sajith on 11/13/21.
//

#include <iostream>

using namespace std;


class Base
{
public:

    virtual void func()
    {
        cout << "Calling from the base\n";
    }
};


class Derived : public Base
{
public:

    void func() override
    {
        cout << "Calling from the derived\n";
    }
};

int main()
{
    Derived derived;
//    derived.func();

    Base b1 = derived;
    b1.func();

    Base b2;
    b2.func();

    Base &rB = derived;
    rB.func();

    Base *pB = &derived;
    pB->func();

    return 0;
}