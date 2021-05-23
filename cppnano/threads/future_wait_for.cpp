//
// Created by sajith on 5/23/21.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <cmath>

void computeSqrt(std::promise<double> &&prms, double input)
{
    std::this_thread::sleep_for(std::chrono::microseconds(900));

    try
    {
        double output = sqrt(input);
        prms.set_value(output);
    } catch (...)
    {
        prms.set_exception(std::current_exception());
    }
}

int main()
{
    double input_data = 42.0;

    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(computeSqrt, std::move(prms), input_data);

    auto status = ftr.wait_for(std::chrono::microseconds(1000));
    if (status == std::future_status::ready)
    {
        try
        {
            std::cout << "Result = " << ftr.get() << "\n";
        } catch (std::runtime_error &e)
        {
            std::cerr << e.what() << "\n";
        }
    } else if (status == std::future_status::timeout || status == std::future_status::deferred)
    {
        std::cout << "Result unavailable\n";
    }

    t.join();

    return 0;
}