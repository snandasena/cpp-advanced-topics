//
// Created by sajith on 5/15/21.
//

#include <iostream>

void func(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int i = 34;
    func(i);
//    func(43); // compile error

    int j = 10;
//    func(i + j); // compile error

    return 0;
}