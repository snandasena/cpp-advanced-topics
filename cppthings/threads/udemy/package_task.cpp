//
// Created by sajith on 10/24/21.
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
    packaged_task<double(int)> task1(calculate_pi);
    future<double> future = task1.get_future();
    thread t(move(task1), 1e7);
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