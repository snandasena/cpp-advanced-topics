#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <utility>

class Vehicle
{
public:
    //default constructor
    Vehicle() : _id(0), _name(new std::string("Default name"))
    {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    //initializing constructor
    explicit Vehicle(int id, std::string name) : _id(id), _name{new std::string(std::move(name))}
    {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }


    // move constructor
    Vehicle(Vehicle &&src) noexcept // r-value reference
    {
        _id = src.getID();
        _name = new std::string(src.getName());

        src.setID(0);
        src.setName("Default Name");

        std::cout << "Vehicle #" << _id << " move constructor called\n";
    }


    // setter and getter
    void setID(int id) { _id = id; }

    [[nodiscard]] int getID() const { return _id; }

    void setName(std::string name)
    {
        *_name = std::move(name);
    }

    [[nodiscard]] std::string getName() const { return *_name; }


private:
    int _id;
    std::string *_name;
};

int main()
{
    // create instances of class Vehicle
    Vehicle v0;    // default constructor
    Vehicle v1(1, "Vehicle 1"); // initializing constructor

    // launch a thread that modifies the Vehicle name
    std::future<void> ftr = std::async(
            [](Vehicle v)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
                v.setName("Vehicle 2");
            }, std::move(v0));

    ftr.wait();
    std::cout << v0.getName() << std::endl;

    return 0;
}