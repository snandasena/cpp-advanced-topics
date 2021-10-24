//
// Created by sajith on 10/23/21.
//

#include <iostream>
#include <future>
#include <thread>
#include <iomanip>
#include <math.h>

using namespace std;

double calculate_pi(int itrs)
{
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
        auto res = calculate_pi(term);
        promise.set_value(res);
    };
    thread t(do_calc, 1e8);
    future<double> future = promise.get_future();
    cout << setprecision(15) << future.get() << endl;
    t.join();
    return 0;
}