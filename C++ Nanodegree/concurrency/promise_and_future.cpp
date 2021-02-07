#include <iostream>
#include <thread>
#include <future>

// Some cons with promises and futures are that they are one way communication (promise -> future) and they are of one-time use.

void modifyMessage(std::promise<std::string> && prms, std::string message) //prms as rvalue reference due to move semantics
{
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // simulate work
    std::string modifiedMessage = message + " has been modified"; 
    prms.set_value(modifiedMessage); // use set_value to change a promise variable
}

int main()
{
    // define message
    std::string messageToThread = "My Message";

    // create promise and future
    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future(); // get_future called on promise 

    // start thread and pass promise as argument
    std::thread t(modifyMessage, std::move(prms), messageToThread); //future has to be used with move semantics

    // print original message to console
    std::cout << "Original message from main(): " << messageToThread << std::endl;

    // retrieve modified message via future and print to console
    std::string messageFromThread = ftr.get();
    std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

    // thread barrier
    t.join();

    return 0;
}
