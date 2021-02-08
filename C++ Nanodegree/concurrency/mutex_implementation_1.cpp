#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex> // 1.
#include<algorithm>

/*
Implement a mutex in 4 simple steps:
    1. Include the <mutex> header
    2. Create an std::mutex
    3. Lock the mutex using lock() before read/write is called
    4. Unlock the mutex after the read/write operation is finished using unlock()

*/

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() {}

    // getters / setters
    void printSize()
    {
        // mutex used here to both to avoid 1 thread reading the vector while another thread writes to it (data race) and
        // also limit only 1 thread have access to std::cout at a time.
        _mutex.lock(); // 3.
        std::cout << "#vehicles = " << _vehicles.size() << std::endl;
        _mutex.unlock(); // 4.
    }

    // typical behaviour methods
    void pushBack(Vehicle &&v)
    {
        _mutex.lock(); // 3.
        _vehicles.emplace_back(std::move(v)); // data race would cause an exception
        _mutex.unlock(); // 4.
    }

private:
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
    std::mutex _mutex; // 2.
};

int main()
{
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles); 
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 1000; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    queue->printSize();

    return 0;
}
