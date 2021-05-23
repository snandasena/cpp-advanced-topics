//
// Created by sajith on 5/22/21.
//

#include <iostream>
#include <thread>

class Vehicle
{
public:

    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
};


int main()
{
    std::thread t(Vehicle());

    return 0;
}