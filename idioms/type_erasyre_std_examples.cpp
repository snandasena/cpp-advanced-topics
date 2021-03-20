//
// Created by sajith on 3/20/21.
//

#include <iostream>
#include <any>
#include <variant>
#include <functional>


struct Increment
{

    int operator()(int x) const { return ++x; }
};


int main()
{
    // 1. std::any (type safe contrainer for single values of any type)
    std::any a;
    a = 10;
    std::cout << std::any_cast<int>(a) << "\n";
    a = std::string{"text"};
    std::cout << std::any_cast<std::string>(a) << "\n";

    // 2. std::variant (type safe union)
    std::variant<int, std::string, char, long> v;

    v = 10;
    std::cout << std::get<int>(v) << "\n";
    v = "string";
    std::cout << std::get<std::string>(v) << "\n";
    // std::cout << std::get<int>(v) << "\n"; can't assign
    // v = 10.0; can't assign

    // 3. std::function (general purpose polymorphic function wrapper)

    std::function<int(int)> f;

    f = [](int x) { return x; };
    std::cout << f(1000) << "\n";

    f = Increment();
    std::cout << f(100) << "\n";

    return 0;
}