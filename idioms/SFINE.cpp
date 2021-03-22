//
// Created by sajith on 3/22/21.
//

// Substitution Failure Ss Not an Error(SFINE)
#include <iostream>

template<typename T>
void foo(const T &)
{
    std::cout << "foo1\n";
}

template<typename T, class U = typename T::Inner>
void foo(const T &)
{
    std::cout << "foo2\n";
};

struct X
{
};

int main()
{
    foo(X());
    return 0;
}

