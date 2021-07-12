//
// Created by sajith on 7/12/21.
//

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

int sushi_count = 5000;

void philosopher(mutex &chopstick)
{
    int sushi_eaten = 0;
    while (sushi_count > 0)
    {
        scoped_lock lock(chopstick);
        if (sushi_count)
        {
            sushi_count--;
            sushi_eaten++;
        }
    }

    cout << "\nThe Philosopher " << this_thread::get_id() << " ate " << sushi_eaten;
}

int main()
{

    mutex chopstick;

    array<thread, 200> philosophers;

    for (auto &i : philosophers)
    {
        i = thread(philosopher, std::ref(chopstick));
    }

    for (auto &t: philosophers)
    {
        t.join();
    }


    printf("\nThe philosophers are done eating...\n");

    return 0;
}