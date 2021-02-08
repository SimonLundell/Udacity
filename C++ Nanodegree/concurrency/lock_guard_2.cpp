#include <iostream>
#include <thread>
#include <mutex>
 
// Will not guarantee B is printed before A, but will work as a way to ensure we get no deadlocks!

std::mutex mutex1, mutex2; // Declaration of mutex should be in global scope
 
void ThreadA()
{
    // Ensure that locks are always executed in the same order
    std::lock(mutex1, mutex2);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
    std::cout << "Thread A" << std::endl;
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    
}
 
void ThreadB()
{
    std::lock(mutex1, mutex2);
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::cout << "Thread B" << std::endl;
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
}
 
void ExecuteThreads()
{
    std::thread t1( ThreadA );
    std::thread t2( ThreadB );
 
    t1.join();
    t2.join();
 
    std::cout << "Finished" << std::endl;
}
 
int main()
{
    ExecuteThreads();
 
    return 0;
}