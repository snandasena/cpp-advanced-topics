//
// Created by sajith on 7/12/21.
//

#include <thread>
#include <mutex>

using namespace std;

int sushi_count = 5000;

void philosopher(mutex &chopstick)
{
    while (sushi_count > 0)
    {
//        chopstick.lock();
        scoped_lock lock(chopstick);
        if (sushi_count)
        {
            sushi_count--;
        }

        if (sushi_count == 10)
        {
            printf("This philosopher has had enough.\n");
            break; // if we use mutex and lock this will cause to happen abandoned locks
        }
//        chopstick.unlock();
    }
}

int main()
{

    mutex chopstick;

    thread barron(philosopher, std::ref(chopstick));
    thread olivia(philosopher, std::ref(chopstick));

    barron.join();
    olivia.join();

    printf("The philosophers are done eating...\n");

    return 0;
}