//
// Created by sajith on 1/15/22.
//

#include <thread>
#include <mutex>
#include <iostream>
#include <string>

using namespace std;


mutex m1;
mutex m2;


void shared_print1(string msg)
{
    lock_guard<mutex> lock1(m1);
    lock_guard<mutex> lock2(m2);
    cout << "Shared print 1 " << msg << endl;
}

void shared_print_deadlock_free1(string msg)
{
    lock(m1, m2);
    lock_guard<mutex> lock1(m1, adopt_lock);
    lock_guard<mutex> lock2(m2, adopt_lock);
    cout << "Shared print 1 " << msg << endl;
}


void shared_print2(string msg)
{
//    lock_guard<mutex> lock1(m2);
//    lock_guard<mutex> lock2(m1);
    lock_guard<mutex> lock1(m1);
    lock_guard<mutex> lock2(m2);
    cout << "Shared print 2 " << msg << endl;
}

void shared_print_deadlock_free2(string msg)
{
    lock(m1, m2);
    lock_guard<mutex> lock1(m2, adopt_lock);
    lock_guard<mutex> lock2(m1, adopt_lock);
    cout << "Shared print 2 " << msg << endl;
}

void func()
{
    for (int i = 0; i < 100; ++i)
    {
//        shared_print1("t1 " + to_string(i));
        shared_print_deadlock_free1("t1 " + to_string(i));
    }
}


int main()
{
    thread t(func);
    for (int i = 0; i < 100; ++i)
    {
//        shared_print2("main " + to_string(i));
        shared_print_deadlock_free2("main " + to_string(i));
    }

    t.join();
    return 0;
}