//
// Created by sajith on 5/22/21.
//

#include <iostream>
#include <thread>


void threadFunctionEven()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}


void threadFunctionOdd()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Odd thread\n";
}

int main()
{

    for (int i = 0; i < 6; ++i)
    {
        if (i % 2 == 0)
        {
            std::thread t(threadFunctionEven);
            t.detach();
        } else
        {
            std::thread t(threadFunctionOdd);
            t.detach();
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work

    std::cout << "End of main is reached" << std::endl;
    return 0;
}