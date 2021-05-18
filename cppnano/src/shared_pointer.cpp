//
// Created by sajith on 5/18/21.
//


#include <memory>
#include <iostream>


int main()
{
    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << "\n";

    {
        std::shared_ptr<int> shared2  = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << "\n";
    }

    std::cout << "shared pointer count = " << shared1.use_count() << "\n";

    return 0;
}