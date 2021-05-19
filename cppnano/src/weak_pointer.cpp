//
// Created by sajith on 5/19/21.
//

#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> mySharedPtr(new int );
    std::cout<< "shared pointer count = "<< mySharedPtr.use_count()<<'\n';

    std::weak_ptr<int> myWeakPtr1(mySharedPtr);
    std::weak_ptr<int> myWeakPtr2(myWeakPtr1);
    std::cout<< "shared pointer count = "<< mySharedPtr.use_count()<<'\n';
    return 0;
}