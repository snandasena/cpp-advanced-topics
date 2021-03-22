//
// Created by sajith on 3/22/21.
//

#include <iostream>

template<typename T>
void foo(const T &)
{
    std::cout << "T not templatized\n";
}

template<template<typename> class T, class U>
void foo(const T<U> &)
{
    std::cout << "T templatized\n";
};

struct X
{
};

template<class T>
struct Y
{
};

int main()
{
    foo(X());

    foo(Y<int>());
    return 0;
}