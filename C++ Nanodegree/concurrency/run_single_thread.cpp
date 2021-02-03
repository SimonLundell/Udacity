// To compile, must use flag "pthread", this is true for all multithreaded programs.
// g++ run_single_thread.cpp -pthread

#include <iostream>
#include <thread>

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulating work
    std::cout << "Finished work in thread" << std::endl;
}

int main() {
    // Create a thread t.
    std::thread t(threadFunction);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main" << std::endl;

    // Wait for thread to finish. Crucial step and must be done! When running, main will continue as normal, if thread not finished
    // before main is finished, we get an error. Using ".join()" makes us wait for the threads to finish.
    t.join();

    return 0;

}