//
// Created by sajith on 3/22/21.
//

#include <iostream>
#include <type_traits>

template<class T>
void foo(T)
{
    std::cout << "T is signed\n";
}

template<class T, class = typename std::enable_if<std::is_unsigned<T>::value>::type>
void foo(T)
{
    std::cout << "T is unsigned\n";
};

struct A
{
};

struct B : A
{
};

template<class T, class = typename std::enable_if<std::is_base_of<A, T>::value>::type>
struct C : T
{
};


int main()
{
    int x = 5;
    foo(x);

    C<B> c;
    return 0;
}