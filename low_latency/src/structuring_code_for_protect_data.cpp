//
// Created by sajith on 11/8/21.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

class some_data
{
    int a;
    string b;

public:
    void do_something() {}
};

class data_wrapper
{

private:
    some_data data;
    mutex m;

public:

    template<typename Function>
    void process_data(Function func)
    {
        lock_guard<mutex> lock(m);
        func(data); // pass "protected" data to user-supplied function
    }
};


some_data *unprotected;

void malicious_function(some_data &protected_data)
{
    unprotected = &protected_data;
}

data_wrapper x;

void foo()
{
    x.process_data(malicious_function); // pass in a malicious function
    unprotected->do_something(); // unprotected access to protected data
}