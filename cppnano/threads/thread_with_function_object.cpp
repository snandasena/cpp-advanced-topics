//
// Created by sajith on 5/22/21.
//

#include <iostream>
#include <thread>

class Vehicle
{
private:
    int _id;
public:
    Vehicle(int i) : _id{i} {}

    void operator()()
    {
        std::cout << "Vehicle object has been created " << _id << std::endl;
    }
};


int main()
{
    std::thread t1((Vehicle(1))); // add an extra pair od parantheses
    std::thread t2 = std::thread(Vehicle(2)); // use copy constructor
    std::thread t3{Vehicle(3)}; // use uniform initialization with braces


    auto func = []()
    {
        std::cout << "Pass by Lambda function for the thread \n";
    };

    std::thread t4(func);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}