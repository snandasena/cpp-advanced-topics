//
// Created by sajith on 11/6/21.
//

#include <iostream>
#include <thread>
#include <future>
#include <string>

using namespace std;

void thread_promise(promise<string> &&prms)
{
    prms.set_value("Hello from thread\n");
}

int main()
{

    promise<string> prms;
    future<string> ftr = prms.get_future();

    thread th(&thread_promise, move(prms));
    cout << "Hello from main\n";

    string str = ftr.get();
    cout << str;
    th.join();
    return 0;
}