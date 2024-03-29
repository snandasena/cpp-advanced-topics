//
// Created by sajith on 10/23/21.
//

#include <iostream>
#include <future>
#include <thread>
#include <iomanip>
#include <cmath>

using namespace std;

double calculate_pi(int itrs)
{
    if (itrs < 1) throw runtime_error{"Terns cannot be less than 1"};
    double sum = 0.0;
    for (int i = 0; i < itrs; ++i)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }
    return sum * 4;
}

int main()
{
    promise<double> promise;
    auto do_calc = [&](int term)
    {
        try
        {
            auto res = calculate_pi(term);
            promise.set_value(res);
        } catch (...)
        {
            promise.set_exception(current_exception());
        }
    };
    thread t(do_calc, 1e8);
    future<double> future = promise.get_future();
    try
    {
        cout << setprecision(15) << future.get() << endl;
    } catch (exception &e)
    {
        cout << e.what() << endl;
    }
    t.join();
    return 0;
}