//
// Created by sajith on 7/8/21.
//

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

unsigned int garlic_count = 0;
unsigned int potato_count = 0;

mutex pencil;


void add_garlic()
{
    pencil.lock();
    garlic_count++;
    pencil.unlock();
}


void add_potato()
{
    pencil.lock();
    potato_count++;
    pencil.unlock();
}

void shopper()
{
    for (int i = 0; i < 10000; ++i)
    {
        add_garlic();
        add_potato();
    }
}

int main()
{
    thread barron(shopper);
    thread olivia(shopper);

    barron.join();
    olivia.join();

    printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u potato.\n", potato_count);
    return 0;
}






