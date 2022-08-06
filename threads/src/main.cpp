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

//
//int common_int = 0;
//mutex mtx;
//void add()
//{
//    mtx.lock();
//    for (int i = 0; i < 100000; ++i)
//    {
//        ++common_int;
//    }
//    mtx.unlock();
//}
//
//int main()
//{
//    thread t1{add};
//    thread t2{add};
//    thread t3{add};
//    thread t4{add};
//
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();
//
//    cout << common_int << endl;
//    return 0;
//}



//int counter = 0;
//mutex mtx;
//
//void run()
//{
//    for (int i = 0; i < 100000; ++i)
//    {
//        if (mtx.try_lock())
//        {
//            ++counter;
//            mtx.unlock();
//        }
//    }
//}
//
//int main()
//{
//    thread t1{run};
//    thread t2{run};
//
//    t1.join();
//    t2.join();
//
//    cout<< counter<<endl;
//    return 0;
//}
//
//

//int x = 0;
//int y = 0;
//mutex m1;
//mutex m2;
//
//void task(int seconds)
//{
//    this_thread::sleep_for(chrono::seconds{seconds});
//}
//
//void incrementXY(int &xy, mutex &m, const char *desc)
//{
//    for (int i = 0; i < 5; ++i)
//    {
//        m.lock();
//        ++xy;
//        cout << desc << " " << xy << '\n';
//        m.unlock();
//        task(1);
//    }
//}
//
//void consumeXY()
//{
//    int use_count = 5;
//    int xplusy = 0;
//
//    while (1)
//    {
//        int lock_result = try_lock(m1, m2);
//        if (lock_result == -1)
//        {
//            if (x != 0 && y != 0)
//            {
//                --use_count;
//                xplusy += x + y;
//                x = 0;
//                y = 0;
//                cout << "X+Y " << xplusy << '\n';
//            }
//            m1.unlock();
//            m2.unlock();
//        }
//        if (use_count == 0) break;
//    }
//}
//
//
//int main()
//{
//    thread t1{incrementXY, ref(x), ref(m1), "X"};
//    thread t2{incrementXY, ref(y), ref(m2), "Y"};
//    thread t3{consumeXY};
//
//    t1.join();
//    t2.join();
//    t3.join();
//    return 0;
//}
//
//

//recursive_mutex mtx;
//int main()
//{
//    for (int i = 0; i < 5; ++i)
//    {
//        mtx.lock();
//        cout << "Locked " << i << '\t';
//    }
//
//    cout<<endl;
//    for (int i = 0; i < 5; ++i)
//    {
//        mtx.unlock();
//        cout << "Unlocked " << i << '\t';
//    }
//
//    return 0;
//}



mutex mtx;
int counter =0;
void task(int task_id)
{
    unique_lock lock(mtx);
    for (int i = 0; i < 10; ++i)
    {
        cout << "T ID: " << task_id << " " << i << '\t';
        ++counter;
        if (i == 9)
        {
            cout << '\n';
        }
    }
}

int main()
{
    thread t1{task, 1};
    thread t2{task, 2};

    t1.join();
    t2.join();

    cout<< counter<<endl;
    return 0;
}































