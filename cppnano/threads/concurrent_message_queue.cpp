//
// Created by sajith on 5/29/21.
//

#include <iostream>
#include <thread>
#include <algorithm>
#include <mutex>
#include <vector>
#include <future>

class Vehicle
{

private:
    int _id;
public:
    explicit Vehicle(int id) : _id(id) {}

    [[nodiscard]] int getId() const
    {
        return _id;
    }
};

class WaitingVehicles
{
public:
    WaitingVehicles() = default;

    Vehicle popBack()
    {
        std::unique_lock<std::mutex> u_lock(_mutex);
        _cond.wait(u_lock, [this]
        {
            return !_vehicles.empty();
        }); // pass unique lock to condition variable

        Vehicle v = _vehicles.back();
        _vehicles.pop_back();

        return v;
    }

    void pushBack(Vehicle &&v)
    {
        // simulate some work
        std::this_thread::sleep_for(std::chrono::microseconds(100));

        std::lock_guard<std::mutex> lock(_mutex);
        std::cout << "   Vehicle #" << v.getId() << " will be added to the queue" << std::endl;
        _vehicles.push_back(v);

        _cond.notify_one(); // notify client after pushing new Vehicle into vector
    }

private:
    std::vector<Vehicle> _vehicles;
    std::mutex _mutex;
    std::condition_variable _cond;
};


int main()
{
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
    std::cout << "Spwaning threads...\n";

    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, v));
    }

    std::cout << "Collecting results...\n";
    while (true)
    {
        Vehicle v = queue->popBack();
        std::cout << "   Vehicle #" << v.getId() << " has been removed from the queue" << std::endl;
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr)
    {
        ftr.wait();
    });

    std::cout << "Finished!\n";
    return 0;
}