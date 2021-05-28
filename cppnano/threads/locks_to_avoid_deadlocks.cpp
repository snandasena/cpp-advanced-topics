//
// Created by sajith on 5/28/21.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;


void ThreadA()
{
    // create deadlock problem
    std::lock_guard<std::mutex> lock2(mutex2);
    std::cout << "Thread A\n";
    std::lock_guard<std::mutex> lock1(mutex1);
}

void ThreadB()
{
    // creat deadlock problem
    std::lock_guard<std::mutex> lock1(mutex1);
    std::cout << "Thread B\n";
    std::lock_guard<std::mutex> lock2(mutex2);
}

void ExecuteThreads()
{
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);

    t1.join();
    t2.join();
}

int main()
{
    ExecuteThreads();
    return 0;
}