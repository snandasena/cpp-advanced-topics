//
// Created by sajith on 11/6/21.
//

#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;

//void to_sin(list<double> &data)
void to_sin(list<double> &&data) // r-value reference
{
//    this_thread::sleep_for(chrono::seconds(1));
    for_each(data.begin(), data.end(), [](double &val)
    {
        val = sin(val);
    });
    for_each(data.begin(), data.end(), [](double &x)
    {
        int cnt = static_cast<int>(10 * x + 10.5);
        for (int i = 0; i < cnt; ++i)
        {
            cout << "*";
        }
        cout << endl;
    });
}


int main()
{
    list<double> list;
    const double pi = 3.141592;
    const double epsilon = 0.0000001;
    for (double x = 0.0; x < 2 * pi + epsilon; x += (pi / 16))
    {
        list.push_back(x);
    }
//    thread th(&to_sin, ref(list));
    thread th(&to_sin, move(list));
    th.join();

//    for_each(list.begin(), list.end(), [](double &x)
//    {
//        int cnt = (10 * x + 10.5);
//        for (int i = 0; i < cnt; ++i)
//        {
//            cout << "*";
//        }
//        cout << endl;
//    });
    return 0;
}