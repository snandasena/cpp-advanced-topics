//
// Created by sajith on 10/24/21.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <condition_variable>

using namespace std;

int main()
{
    condition_variable condition;
    mutex mtx;
    bool ready = false;
    thread task([&]()
                {
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    unique_lock<mutex> lock(mtx);
                    ready = true;
                    lock.unlock();
                    condition.notify_one();
                });

    unique_lock<mutex> lock(mtx);
//    while (!ready)
//    {
//        condition.wait(lock);
//    }

    condition.wait(lock, [&]() { return ready; });
    cout << "Ready status: " << boolalpha << ready << endl;
    task.join();
    cout << "Ready status: " << boolalpha << ready << endl;
    return 0;


}