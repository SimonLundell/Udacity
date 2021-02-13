#include <iostream>
#include <random>
#include "TrafficLight.h"
#include <future>
#include <queue>

/* Implementation of class "MessageQueue" */


template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function.
    std::unique_lock<std::mutex> uLock(_mtx);
    //std::cout << "timeout3\n";
    _cond.wait(uLock, [this](){ return !_queue.empty(); });
    //std::cout << "timeout4\n";
    T item = std::move(_queue.back());
    _queue.clear();

    return item;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex> 
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.
    std::lock_guard<std::mutex> sLock(_mtx);
    _queue.push_back(std::move(msg));
    _cond.notify_one(); // check this in Udacity class.
    std::cout << "Thread " << msg << " entered the queue\n";
    
}


/* Implementation of class "TrafficLight" */


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
    // FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called. 
    // To do this, use the thread queue in the base class.
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}

// virtual function which is executed in a thread
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
