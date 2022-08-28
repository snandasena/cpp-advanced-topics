//
// Created by sajith on 8/26/22.
//

#include "base.h"

template<typename T>
concept TinyType =
requires(T)
{
    requires sizeof(T) <= 4;
};

template<typename T>
TinyType auto add(T a, T b)
{
    return a + b;
}

template<typename T>
concept Addable = requires(T a, T b)
{
    { a + b } noexcept ->std::convertible_to<int>;
};

Addable auto add2(Addable auto a, Addable auto b)
{
    return a + b;
}

int main()
{
    char a{'a'};
    char b{'b'};
    std::cout << add(a, b) << std::endl;
    int x = 10;
    double y = 10.6;
    std::cout << add2(b, y) << std::endl;

    std::string s{"hello"};
    std::string r{"world"};

//    add2(s, r);
    return 0;
}