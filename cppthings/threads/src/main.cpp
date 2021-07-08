//
// Created by sajith on 7/6/21.
//

#include <thread>
#include <iostream>
#include <chrono>
#include <unistd.h>

using namespace std;

void kitchen_clear()
{
    while (true)
    {
        printf("Olivia cleaned the kitchen\n");
        std::this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{

    thread olivia(kitchen_clear);
    olivia.detach(); // allow to running in background
    for (int i = 0; i < 3; ++i)
    {
        printf("Barron is cooking.. \n");
        this_thread::sleep_for(chrono::microseconds(600));
    }
    printf("Barron is done\n");

//    olivia.join();
    return 0;
}