//
// Created by sajith on 5/23/21.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>

int main()
{
    const int num_threads = 10;
    std::vector<std::thread> threads;
    threads.reserve(num_threads);

    for (int i = 0; i < num_threads; ++i)
    {
        threads.emplace_back(
                [&i]()
                {
                    std::this_thread::sleep_for(std::chrono::microseconds(10 * i));

                    std::cout << " Hello from worker thread #" << i << std::endl;
                }
        );
    }

    for (auto &t: threads)
    {
        t.join();
    }
    return 0;
}