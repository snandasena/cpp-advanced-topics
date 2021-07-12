//
// Created by sajith on 7/11/21.
//

#include <thread>
#include <mutex>

using namespace std;

int sushi_count = 5000;

void philosopher(mutex &first_chopstick, mutex &second_chopstick)
{
    while (sushi_count > 0)
    {
        first_chopstick.lock();
        if (!second_chopstick.try_lock())
        {
            first_chopstick.unlock();
            this_thread::yield();
        }
        else
        {
            if (sushi_count)
            {
                sushi_count--;
            }

            second_chopstick.unlock();
            first_chopstick.unlock();
        }

    }
}

int main()
{
    mutex chopstick_a, chopstick_b;
    thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    thread steve(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    thread nikki(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));

    barron.join();
    olivia.join();
    steve.join();
    nikki.join();

    printf("The philosophers are done eating...\n");


    return 0;
}