//
// Created by sajith on 11/13/21.
//

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class MyClass
{
public:
    MyClass()
    {
        cout << "Constructor called\n";
    }


    ~MyClass()
    {
        cout << "Destructor called\n";
    }


    void func()
    {
        cout << "Func called\n";
    }

    MyClass(MyClass &&p) = default;
    MyClass(MyClass const &p) = default;
};

void CallFunc1(MyClass &p)
{
    cout << "CALL01\n";
    p.func();
}

void CallFunc2(MyClass p)
{
    cout << "CALL02\n";
    p.func();
}

void CallFunc3(MyClass &&p)
{
    cout << "CALL03\n";
    p.func();
}

void CallFunc4(MyClass *p)
{
    cout << "CALL04\n";
    p->func();
}

int main()
{
//    auto pMyClass = std::make_unique<MyClass>();
    auto pMyClass = std::make_shared<MyClass>();

    pMyClass->func();
    CallFunc1(*pMyClass);
    CallFunc2(*pMyClass);
    CallFunc3(std::move(*pMyClass));
    CallFunc4(pMyClass.get());
    return 0;
}


