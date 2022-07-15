//
// Created by sajith on 7/15/22.
//


#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <algorithm>

int soup_servings = 10;
std::mutex slow_cooker_lid;
std::condition_variable soup_taken;

void hungry_person(int id)
{
    int put_lid_back = 0;
    while (soup_servings)
    {
        std::unique_lock lid_lock(slow_cooker_lid);
//        soup_taken.wait(lid_lock, [&put_lid_back, id]()
//        {
//            ++put_lid_back;
//            return (id != soup_servings % 5) && soup_servings;
//        });

        while ((id != soup_servings % 5) && soup_servings)
        {
            ++put_lid_back;
            soup_taken.wait(lid_lock);
        }

        if (soup_servings)
        {
            --soup_servings;
            lid_lock.unlock();
            soup_taken.notify_all();
        }
    }
    printf("Person %d put the lid back %u times. \n", id, put_lid_back);
}

int main()
{
    std::thread hungry_threads[5];
    for (int i = 0; i < 5; ++i)
    {
        hungry_threads[i] = std::thread(hungry_person, i);
    }

    for (auto &item: hungry_threads)
    {
        item.join();
    }

    return 0;
}


