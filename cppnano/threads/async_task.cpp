
//
// Created by sajith on 5/23/21.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <future>


double divideByNumber(double num, double denom)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work

    if (denom == 0)
        throw std::runtime_error("Exception from thread: Division by zero!");

    return num / denom;
}


int main()
{

    double num = 42.0, deno = 2.0;

    std::future<double> ftr = std::async(divideByNumber, num, deno);

    try
    {
        double result = ftr.get();
        std::cout << "Result = " << result << "\n";
    } catch (std::runtime_error &e)
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}

