
//
// Created by sajith on 9/5/22.
//


#include <bits/stdc++.h>

using namespace std;

template<typename T>
T maximum(T a, T b)
{
    return a > b ? a : b;
}

struct A
{
    int a;

    A(int _a) : a{_a}
    {}

    bool operator<=>(const A &other) const
    {
        return this->a >= other.a;
    }

    void call()
    {
        cout << "CALLING A()::call()\n";
    }

};

struct B
{
    int b;

    B(int _b) : b{_b}
    {}
};


template<typename T>
void func(T t)
{
    t.call();
}

template<typename T>
T temp_func(const T &a, const T &b)
{
    cout << "REF B" << &b << endl;
    cout << "REF A" << &a << endl;
    return a > b ? a : b;
}


int main()
{
    A a = 10;
    A b = 20;

//    auto res = maximum<int>(a, b); not compile
    auto res = maximum(a, b); // will compile

    func(a);

    auto res2 = temp_func(a, b);
    cout << "REF B" << &b << endl;
    cout << "REF A" << &a << endl;

    return 0;
}