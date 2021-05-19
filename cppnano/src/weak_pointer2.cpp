//
// Created by sajith on 5/19/21.
//

#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> mySharedPtr(new int);
    std::weak_ptr<int> myWeakPtr(mySharedPtr);

    mySharedPtr.reset(new int);
    if (myWeakPtr.expired())
    {
        std::cout << "Weak pointer expired!\n";
    }
    return 0;
}