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
    return 0;
}
