//
// Created by sajith on 3/23/21.
//


#include <iostream>

struct X
{

};

struct Y : X
{

};

struct Z
{
    X x;
    int a;
};

struct W
{
    int x;
};

struct K : W
{
};

struct D : X
{
    int x;
};

struct F : W
{
    int a;
};

int main()
{
    std::cout << sizeof(X) << "\n";
    std::cout << sizeof(Y) << "\n";
    std::cout << sizeof(Z) << "\n";
    std::cout << sizeof(W) << "\n";
    std::cout << sizeof(K) << "\n";
    std::cout << sizeof(D) << "\n";
    std::cout << sizeof(F) << "\n";
    return 0;
}