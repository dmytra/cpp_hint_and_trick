#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

//𝗛𝗼𝘄 𝘁𝗼 𝗕𝗹𝗼𝗰𝗸 𝗮 𝗧𝗵𝗿𝗲𝗮𝗱 𝗨𝗻𝘁𝗶𝗹 𝗮𝗻 𝗘𝘃𝗲𝗻𝘁 𝗢𝗰𝗰𝘂𝗿𝘀: 𝗨𝘀𝗶𝗻𝗴 𝗖𝗼𝗻𝗱𝗶𝘁𝗶𝗼𝗻 𝗩𝗮𝗿𝗶𝗮𝗯𝗹𝗲𝘀 𝗶𝗻 𝗖++
//https://www.linkedin.com/posts/nikolai-kutiavin_cpp-concurrency-multithreading-activity-7262464235392192512-MNBj/?utm_source=share&utm_medium=member_desktop

std::queue<int> dataQueue;
std::mutex queueMutex;
std::condition_variable condVar;
bool done = false; // Flag to indicate when to stop the worker thread

// Worker thread function
void workerThread() {
    while(true) {
    std::unique_lock<std::mutex> lock(queueMutex);
    
// Watt on the condition variable until the queue is not empty or done flag is true
    condVar.wait(lock, [] { return !dataQueue.empty() || done; });
    
// Exit the loop if done is true and the queue is empty
    if (done && dataQueue.empty()) {
        break;
    }
    
// Process the item in the queue
    while (!dataQueue.empty()) {
        int value = dataQueue.front();
        dataQueue.pop();
        lock.unlock(); // Unlock the mutex while processtng
        
// Simulate work by sleeping for a bit
        std::cout << "Worker thread processed value: " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lock.lock(); // Re-lock before checking the queue again
    }
}
}

int main() {
    //the worker thread
    std::thread worker(workerThread);
    
// Main thread fills the1:7 queuer,), with values
    for(int i = 1; i <= 10; ++i) {
    std::lock_guard<std::mutex> lock(queueMutex);
        dataQueue.push(i);
        std::cout << "Main thread added value: " << i << std::endl;
    condVar.notify_one(); // Notify the worker thread
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate delay In addtng item)
    }
    // Set done flag and notify worker thread to finish processing ,
    {
    std::lock_guard<std::mutex> lock(queueMutex);
    }
        
    done = true;
    condVar.notify_one();
    
    // Wait for the worker thread to finish
    
    worker.join();
    
    std::cout << "All tasks completed.\n";
    return 0;
}

