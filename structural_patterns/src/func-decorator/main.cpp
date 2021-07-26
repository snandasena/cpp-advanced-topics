//
// Created by sajith on 7/26/21.
//


#include <iostream>

int Square(int x)
{
    return x * x;
}

int Add(int x, int y)
{
    return x + y;
}


float Divide(float x, float y)
{
    return x / y;
}

template<typename Function>
auto PrintResult(Function func)
{
    return [func](auto &&...args)
    {
        std::cout << "Result is: ";
        return func(args...);
    };
}

template<typename Function>
auto SafeDivision(Function func)
{
    return [func](auto a, auto b)
    {
        if (b == 0)
        {
            std::cout << "Divide by zero\n";
            b = 1;
        }

        return func(a, b);
    };
}

int main()
{

    auto result = PrintResult(Square);
    std::cout << result(5) << std::endl;

    auto add = PrintResult(Add);
    std::cout << add(10, 40) << std::endl;

    auto divide = PrintResult(SafeDivision(Divide));
    std::cout << divide(10, 5) << std::endl;

    return 0;
}