//
// Created by sajith on 5/19/21.
//

#include <iostream>
#include <memory>

class MyClass
{
private:
    int _member;

public:

    MyClass(int val) : _member{val} {}

    void printVal()
    {
        std::cout << ", managed object " << this << " with val = " << _member << "\n";
    }
};

void f(std::unique_ptr<MyClass> ptr)
{
    std::cout << "unique_ptr " << &ptr;
    ptr->printVal();
}

int main()
{
    std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(32);
    std::cout << "unique_ptr " << &uniquePtr;

    uniquePtr->printVal();
    f(std::move(uniquePtr));

    if (uniquePtr)
    {
        uniquePtr->printVal();
    }
    return 0;
}


