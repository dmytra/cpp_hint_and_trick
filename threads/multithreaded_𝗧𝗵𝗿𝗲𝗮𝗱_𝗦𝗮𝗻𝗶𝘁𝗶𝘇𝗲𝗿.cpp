#include <iostream>
#include <thread>
#include <vector>

// https://www.linkedin.com/posts/nikolai-kutiavin_multithreaded-multithreading-cpp-ugcPost-7257098270353641472-2S7G/?utm_source=share&utm_medium=member_desktop

int counter = 0; // Shared variable

// Function to increment the counter
void incrementCounter() {
    for (int i = 0; i < 1000; ++i) {
        // Increment the shared counter without synchronization
        ++counter;
    }
}
 
int main() {
    const int numThreads = 10; // Number of threads to create
    std::vector<std::thread> threads;
    
// Launch multiple threads to increment the counter
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(incrementCounter));
    }
    
// Watt for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
    
// Print the final value of counter
    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}

