#include <iostream>
#include <random>
#include "TrafficLight.h"
#include <future>
#include <queue>

/* Implementation of class "MessageQueue" */


template <typename T>
TrafficLightPhase MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait() 
    // to wait for and receive new messages and pull them from the queue using move semantics. 
    // The received object should then be returned by the receive function.
    std::unique_lock<std::mutex> uLock(_mtx);
    _cond.wait(uLock, [this](){ return !_queue.empty(); });
    auto item = std::move(_queue.back());
    _queue.pop_back();

    return item;
}

template <typename T>
void MessageQueue<T>::send(TrafficLightPhase &&msg)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex> 
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.
    std::lock_guard<std::mutex> uLock(_mtx);
    _queue.push_back(std::move(msg));
    std::cout << "Message in thread " << msg << " entered the queue\n";
    _cond.notify_one(); // check this in Udacity class.
}


/* Implementation of class "TrafficLight" */


TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
}

void TrafficLight::waitForGreen()
{
    // FP.5b : add the implementation of the method waitForGreen, in which an infinite while-loop 
    // runs and repeatedly calls the receive function on the message queue. 
    // Once it receives TrafficLightPhase::green, the method returns.
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::simulate()
{
    // FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called. 
    // To do this, use the thread queue in the base class.
    TrafficObject::threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    // FP.2a : Implement the function with an infinite loop that measures the time between two loop cycles 
    // and toggles the current phase of the traffic light between red and green and sends an update method 
    // to the message queue using move semantics. The cycle duration should be a random value between 4 and 6 seconds. 
    // Also, the while-loop should use std::this_thread::sleep_for to wait 1ms between two cycles.

    // Initate start time with current time
    std::clock_t start = std::clock();
    // define a random generator
    std::default_random_engine generator;
    // define a distribution
    std::uniform_int_distribution<int> distribution(4,6);
    // create variable with random value between 4-6
    int random = distribution(generator);
    // infinite loop
    while (true) {
        // Call sleep for better CPU-usage 
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // if current-time - start time is > random number
        if ((((std::clock() - start) / CLOCKS_PER_SEC)) >= random) {
            // Alternate traffic lights
            if (_currentPhase == red) {
                _currentPhase = green;
            } else {
                _currentPhase = red;
            }
            // start a thread as async, on function send in messagequeue with type TLP. Done on pointer in queue with
            // argument _currentPhase.
            std::future<void> t = std::async(std::launch::async, &MessageQueue<TrafficLightPhase>::send, queue, std::move(_currentPhase));
            // Wait for the task to finish.
            t.wait();
            // set new start time for next iteration
            start = std::clock();
            // generate new number
            random = distribution(generator);
        }
        
    }
}