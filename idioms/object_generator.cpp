//
// Created by sajith on 3/22/21.
//

#include <iostream>
#include <utility>
#include <tuple>

template<typename... Args>
auto makeTuple(Args &&... args)
{
    return std::tuple<Args...>(std::forward<Args>(args)...);
};


int main()
{
    auto t = makeTuple(10, std::string{"text"}, 'x');
    return 0;
}