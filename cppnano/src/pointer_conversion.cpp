//
// Created by sajith on 5/19/21.
//

#include <iostream>
#include <memory>

int main()
{
    // construct unique pointer
    std::unique_ptr<int> uniquePtr(new int);

    // (1) shared pointer from unique pointer
    std::shared_ptr<int> sharedPtr1 = std::move(uniquePtr);

    // (2) shared pointer from weak pointer
    std::weak_ptr<int> weakPtr(sharedPtr1);
    std::shared_ptr<int> sharedPtr2 = weakPtr.lock();

    /*
     * In (3), a raw pointer is extracted from a shared pointer.
     * However, this operation does not decrease the reference
     * count within sharedPtr2. This means that calling delete on
     * rawPtr in the last line before main returns will generate a
     * runtime error as a resource is trying to be deleted
     * which is managed by sharedPtr2 and has already been removed
     *
     */

    // (3) raw pointer from shared( or unique) pointer
    int *rawPtr = sharedPtr2.get();

    delete rawPtr; // runtime error
    return 0;
}