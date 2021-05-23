//
// Created by sajith on 5/23/21.
//

#include <iostream>
#include <thread>


int main()
{
    int id = 10;

    auto f1 = [id]()
    {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::cout << "Id is " << id << "\n";
    };

//    f1();

    auto f2 = [&id]()
    {
        ++id;
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::cout << "Id is " << id << "\n";
    };


    auto f3 = [id]() mutable
    {
        ++id;
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::cout << "Id is " << id << "\n";
    };

    auto f4 = [](const int id) // pass parameter
    {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::cout << "Id is " << id << "\n";
    };

    auto f5 = [&id]() mutable
    {
        ++id;
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::cout << "Id is " << id << "\n";
    };

    std::thread t1(f1);
    std::thread t2(f2);
    std::thread t3(f3);
    std::thread t4(f4, 1000);
    std::thread t5(f5);

    std::cout << "ID in main is " << id << "\n";

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();


    std::cout << "ID in main is " << id << "\n";

    f4(++id);
    std::cout << "ID in main is " << id << "\n";
    f4(id++);
    std::cout << "ID in main is " << id << "\n";

    return 0;
}
