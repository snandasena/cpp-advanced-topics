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
//        first_chopstick.lock(); // replaced by scoped_lock
//        second_chopstick.lock(); // replaced by scoped_lock

        std::scoped_lock lock(first_chopstick, second_chopstick);
        if (sushi_count)
        {
            sushi_count--;
        }

//        second_chopstick.unlock(); // replaced by scoped_lock
//        first_chopstick.unlock(); // replaced by scoped_lock
    }
}

int main()
{
    mutex chopstick_a, chopstick_b;
    thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));

    // this will be supported to create deadlocks
//    thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    thread olivia(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));

    barron.join();
    olivia.join();

    printf("The philosophers are done eating...\n");

    return 0;
}