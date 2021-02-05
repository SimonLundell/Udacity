#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>
/*
Threads and tasks are used for different problems. Threads have more to do with latency. When you have functions that can block 
(e.g. file input, server connection), threads can avoid the program to be blocked, when e.g. the server is waiting for a response. 
Tasks on the other hand focus on throughput, where many operations are executed in parallel.
*/
double divideByNumber(double num, double denom) // return type changed from void to double as async uses a simple return
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work

    if (denom == 0)
        throw std::runtime_error("Exception from thread: Division by zero!");

    return num / denom;
}


int main()
{
    // use async to start a task
    double num = 42.0, denom = 2.0;
    // no thread created, also substituted by async.
    std::future<double> ftr = std::async(/*std::launch::deferred,*/divideByNumber, num, denom); // no promise created, future directly with async.
    // deferred forces to run syncroneous execution of thread, without the command the system decides
    // retrieve result within try-catch-block
    try
    {
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }
    // there is also no join with tasks. 
    return 0;
}