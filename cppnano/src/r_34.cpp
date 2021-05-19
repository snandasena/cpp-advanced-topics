//
// Created by sajith on 5/19/21.
//

#include <iostream>
#include <memory>
#include "my_class.h"

void f(std::shared_ptr<MyClass> ptr)
{
    std::cout << "shared_ptr (ref_cnt= " << ptr.use_count() << " )" << &ptr;
    ptr->printVal();
}

int main()
{
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(43);
    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << " )" << &sharedPtr;

    sharedPtr->printVal();
    f(sharedPtr);
    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << " )" << &sharedPtr;
    sharedPtr->printVal();

    return 0;
}