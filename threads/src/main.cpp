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
//
//void run()
//{
//    cout << "child thread\n";
//    this_thread::sleep_for(chrono::seconds{4});
//    cout << "child thread finished\n";
//}
//
//int main()
//{
//    thread t{run};
//    t.detach();
//    cout << "main thread\n";
//    this_thread::sleep_for(chrono::seconds{2});
//    if (t.joinable())
//    {
//        t.detach();
//    }
//    return 0;
//}


int common_int = 0;
mutex mtx;
void add()
{
    mtx.lock();
    for (int i = 0; i < 100000; ++i)
    {
        ++common_int;
    }
    mtx.unlock();
}

int main()
{
    thread t1{add};
    thread t2{add};
    thread t3{add};
    thread t4{add};

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << common_int << endl;
    return 0;
}
















