//
// Created by sajith on 5/22/21.
//

#include <thread>
#include <iostream>

void thread_task()
{
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    std::cout << "Finished work in thead\n";
}

int main()
{
    std::cout << "Current thread " << std::this_thread::get_id() << "\n";

    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "This pc supports concurrency with " << cores << "\n";

    std::thread t(thread_task);

    t.detach(); // detach thead and continue with main

    std::this_thread::sleep_for(std::chrono::microseconds(50));
    std::cout << "Finished work in main\n";
//    t.join();

    return 0;

}