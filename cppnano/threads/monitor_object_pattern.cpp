//
// Created by sajith on 5/28/21.
//

#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include <algorithm>


class Vehicle
{
public:
    explicit Vehicle(int id) : _id(id) {}

    [[nodiscard]] int getID() const { return _id; }

private:
    int _id;
};


class WaitingVehicles
{

public:
    WaitingVehicles() = default;

    void printIds()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        for (auto &v: _vehicles)
        {
            std::cout << "   Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
        }
    }

    void pushBack(Vehicle &&v)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.emplace_back(v);

        // simulate some work
        std::this_thread::sleep_for(std::chrono::microseconds(500));
    }

private:
    std::vector<Vehicle> _vehicles;
    std::mutex _mutex;
};


int main()
{
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
    std::cout << "Spawning threads...\n";
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue,
                                        v));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr)
    {
        ftr.wait();
    });

    std::cout << "Collecting results...\n";
    queue->printIds();

    return 0;
}