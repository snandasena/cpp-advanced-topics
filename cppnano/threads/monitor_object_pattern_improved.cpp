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
    WaitingVehicles() : _numVehicles(0) {};

    int getNumVehicles()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return _numVehicles;
    }

    bool dataIsAvailable()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        return !_vehicles.empty();
    }

    void printIds()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        for (auto &v: _vehicles)
        {
            std::cout << "   Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
        }
    }

    Vehicle popBack()
    {
        std::lock_guard<std::mutex> lock(_mutex);
        Vehicle v = _vehicles.back();
        _vehicles.pop_back();
        --_numVehicles;
        return v;
    }

    void pushBack(Vehicle &&v)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.emplace_back(v);

        // simulate some work
        std::this_thread::sleep_for(std::chrono::microseconds(500));
        ++_numVehicles;
    }

private:
    std::vector<Vehicle> _vehicles;
    std::mutex _mutex;
    int _numVehicles;
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
    std::cout << "Collecting results...\n";

    while (true)
    {
        if (queue->dataIsAvailable())
        {
            Vehicle v = queue->popBack();
            std::cout << " Vehicle #" << v.getID() << " has been removed from the queue\n";

            if (queue->getNumVehicles() <= 0)
            {
                std::this_thread::sleep_for(std::chrono::microseconds(200));
                break;
            }
        }
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr)
    {
        ftr.wait();
    });

    std::cout << "Finished: " << queue->getNumVehicles() << " vehicle(s) left in the queue\n";
    return 0;
}