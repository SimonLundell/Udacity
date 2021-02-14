#include <iostream>
#include <random>
#include "TrafficLight.h"
#include <future>
#include <queue>
#include <ctime>

/* Implementation of class "MessageQueue" */


template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function.
    std::unique_lock<std::mutex> uLock(_mtx);
    _cond.wait(uLock, [this](){ return !_queue.empty(); });
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
    _queue.emplace_back(std::move(msg));
    _cond.notify_one(); // check this in Udacity class. 
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(4.0, 6.0);
    float cycleTime = dist(gen);
    auto timer = time(0);
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        auto timer2 = time(0);
        if (timer2-timer > cycleTime) {
            _currentPhase == red ? _currentPhase = green : _currentPhase = red;
            TrafficLightPhase msg = _currentPhase;
            _messageQueue.send(std::move(msg));
            cycleTime = dist(gen);
            timer = time(0);
        }
    }
}
