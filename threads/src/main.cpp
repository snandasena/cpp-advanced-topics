//
// Created by sajith on 8/6/22.
//


#include <iostream>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

//void run()
//{
//    cout << "Child thread\n";
//    this_thread::sleep_for(chrono::seconds{2});
//}
//
//int main()
//{
//    cout << "Main thread before\n";
//    thread t{run};
////    t.join();
//    this_thread::sleep_for(chrono::seconds{2});
//    cout << "Still in main thread\n";
//    if (t.joinable())
//    {
//        t.join();
//    }
//    cout << "Main thread after\n";
//    return 0;
//}

void run()
{
    cout << "child thread\n";
    this_thread::sleep_for(chrono::seconds{5});
    cout << "child thread finished\n";
}

int main()
{
    thread t{run};
    t.detach();
    cout << "main thread\n";
    this_thread::sleep_for(chrono::seconds{2});
    return 0;
}