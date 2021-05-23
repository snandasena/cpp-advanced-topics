//
// Created by sajith on 5/23/21.
//


#include <iostream>
#include <thread>
#include <string>

class Vehicle
{

private:
    int _id;
    std::string _name;

public:

    Vehicle() : _id(0) {}

    void addId(int id)
    {
        _id = id;
    }

    void printId()
    {
        std::cout << "Vehicle ID= " << _id << std::endl;
    }

    void setNameByReference(std::string &name)
    {
        _name = name;
    }

    void setNameByValue(std::string name)
    {
        _name = name;
    }

    void printName()
    {
        std::cout << "Vehicle name= " << _name << std::endl;
    }
};

void printName(std::string &name)
{
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    name += " from thread appended";
    std::cout << name << std::endl;
}

int main()
{
    std::string name("My Thread");
    std::thread t(printName, std::ref(name));
    t.join();

    Vehicle v1, v2;
    std::thread t1 = std::thread(&Vehicle::addId, v1, 1);
    std::thread t2 = std::thread(&Vehicle::addId, &v2, 2);

    t1.join();
    t2.join();

    v1.printId();
    v2.printId();

    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t3 = std::thread(&Vehicle::addId, v, 21);
    std::thread t4 = std::thread(&Vehicle::setNameByValue, v, "MyName");
    t3.join();
    t4.join();
    v->printId();
    v->printName();
    std::string name2("Name2");

    std::thread t5 = std::thread(&Vehicle::setNameByReference, v, std::ref(name2));
    t5.join();

    v->printName();
    return 0;
}