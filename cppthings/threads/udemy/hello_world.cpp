//
// Created by sajith on 10/23/21.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std;


void tack()
{
    for (int i = 0; i < 10; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds (500));
        cout << i << " ";
    }
    cout << endl;
}

void task(int &cnt, mutex &mtx)
{
    for (int i = 0; i < 1e7; ++i)
    {
        std::lock_guard<mutex> lock(mtx);
        ++cnt;
    }
}

typedef long int li;

int main()
{
//    thread t2(tack);
//    thread t1(tack);
//    atomic<long> cnt{0};
    mutex mx;
//    const li iterations = 1E7;
    int cnt = 0;
//    auto func = [&]()
//    {
//        for (li i = 0; i < iterations; ++i)
//        {
//            lock_guard<mutex> (&mx);
//            ++cnt;
////            mx.unlock();
//        }
//    };
    thread t3(task, std::ref(cnt), std::ref(mx));
    thread t4(task, std::ref(cnt), std::ref(mx));

//    t1.join();
//    t2.join();
    t3.join();
    t4.join();

    cout << "Count " << cnt << endl;
    return 0;
}