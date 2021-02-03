// Be very careful with detach, it will allow to run program without .join (sometimes necessary). If main finishes before the thread, thread is
// abruptly cloesed and resources are not freed. This needs to be handled in the thread destructor.
// NOTE A deteched thread can never be joined again.

#include <iostream>
#include <thread>

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread\n"; 
}

int main()
{
    // create thread
    std::thread t(threadFunction);

    // detach thread and continue with main
    t.detach();

    // do something in main()
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in main\n";

    return 0;
}