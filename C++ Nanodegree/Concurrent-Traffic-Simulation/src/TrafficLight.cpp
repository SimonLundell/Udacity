#include <iostream>
#include <random>
#include "TrafficLight.h"
#include <future>
#include <queue>

// Generic queue manager
template <typename T>
T MessageQueue<T>::receive()
{
    std::unique_lock<std::mutex> uLock(_mtx);
    _cond.wait(uLock, [this](){ return !_queue.empty(); }); // lambda
    T item = std::move(_queue.back());
    _queue.clear(); // has to clear the queue...

    return item;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    std::lock_guard<std::mutex> uLock(_mtx);
    _queue.push_back(std::move(msg));
    _cond.notify_one();
}

TrafficLight::TrafficLight()
{
    // Constructor instantiating as red.
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    // Infinite loop
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // receive the state of the traffic-light in the queue
        auto light = _messageQueue.receive();
        // if it is green, return
        if (light == green) {
            return;
        }
    }
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate()
{
    // Starting cycleThroughPhases in a thread on current object and adding it to the thread vector
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}

void TrafficLight::cycleThroughPhases()
{
    // define a random generator
    std::random_device rd;
    // define a distribution
    std::uniform_real_distribution<double> dist(4.0, 6.0);
    // create a cycle-time with a true random distribution
    float cycleTime = dist(rd);
    // get current time
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed;

    // infinite loop
    while (true) {
        // Call sleep for better CPU-usage 
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // Elapsed time from start
        elapsed = std::chrono::high_resolution_clock::now() - start;
        if (elapsed.count() > cycleTime) {
            // New start when condition is met
            start = std::chrono::high_resolution_clock::now();
            // New cycle time
            cycleTime = dist(rd);
            // Alternate traffic lights
            if (_currentPhase == red) {
                _currentPhase = green;
            } else {
                _currentPhase = red;
            }
            // move trafficlightphase to the queue
            auto msg = _currentPhase;
            _messageQueue.send(std::move(msg));
        }
    }
}
