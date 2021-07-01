//
// Created by sajith on 7/1/21.
//

#include <iostream>

template<typename T>
T summer(T v)
{
    return v;
}


template<typename T, typename ... Args>
T summer(T first, Args ... args)
{
    return first + summer(args ...);
}


int main()
{
    std::cout << "summer(1, 2, 13, 100) = " << summer(1, 2, 13, 100) << std::endl;
    return 0;
}
