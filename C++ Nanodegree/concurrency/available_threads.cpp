#include <iostream>
#include <thread> // This allows for concurrency through threads, part of std.

int main() {

    // Main is one thread, referred to commonly as "main thread"
    std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;

    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "This machine support concurrency with " << nCores << " cores available" << std::endl;

    return 0;
}