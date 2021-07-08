//
// Created by sajith on 7/8/21.
//

#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
#include <atomic>

using namespace std;

mutex pencil;

//unsigned int garlic_count = 0;
atomic<unsigned int> garlic_count(0);

void shopper()
{
//    for (int i = 0; i < 5; ++i)
//    {
//        cout << "Shopper" << this_thread::get_id() << " is thinking ... \n";
//        this_thread::sleep_for(chrono::milliseconds(500));
//        pencil.lock();
//        garlic_count++;
//        pencil.unlock();
//    }

    for (int i = 0; i < 10000000; ++i)
    {
        garlic_count++;
    }

}

int main()
{
    thread barron(shopper);
    thread olivia(shopper);

    barron.join();
    olivia.join();

    printf("We should buy %u garlic. \n", garlic_count.load());

    return 0;
}