//
// Created by sajith on 5/18/21.
//


#include <memory>
#include <iostream>

class MyClass
{
public:
    std::shared_ptr<MyClass> _member;

    ~MyClass()
    {
        std::cout << "Destructor of MyClass called\n";
    }
};

int main()
{
    std::shared_ptr<MyClass> myClass1(new MyClass);
    std::shared_ptr<MyClass> myClass2(new MyClass);

    return 0;
}