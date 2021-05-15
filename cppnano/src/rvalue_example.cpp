//
// Created by sajith on 5/15/21.
//


#include <iostream>

void func(int &&val)
{

    std::cout << "val = " << val << std::endl;
}

int main()
{
    func(43);
    int i = 34;

    // cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
//    func(i);

    return 0;
}
