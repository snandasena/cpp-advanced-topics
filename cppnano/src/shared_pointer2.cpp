//
// Created by sajith on 5/18/21.
//


#include <memory>
#include <iostream>

class MyClass
{
public:
    ~MyClass()
    {
        std::cout<<"Destructor of MyClass called\n";
    }
};

int main()
{
    std::shared_ptr<MyClass> shared1(new MyClass);
    std::cout << "shared pointer count = " << shared1.use_count() << "\n";

    shared1.reset(new MyClass);

    std::cout << "shared pointer count = " << shared1.use_count() << "\n";

    return 0;
}