#include <iostream> 
#include <thread> 
#include <chrono> 
#include <condition_variable>
 
int main() { 
bool ready = false; 
std::condition_variable condition; 
std::mutex mtx; 
std::thread t1([&]() { 
	std::cout << "\n start tgread \n";
	std::this_thread::sleep_for(std::chrono::microseconds(2000000)); 
	std::unique_lock<std::mutex> lock(mtx); 
	ready = true; 
	lock.unlock(); 
	condition.notify_one(); 
	std::cout << "\n end tgread \n";

}); 
std::unique_lock<std::mutex> lock(mtx); 
while (!ready) { 
	condition.wait(lock); 
} 
t1.join();
return 0 ; 
}

/*
 * link 
 * https://www.linkedin.com/posts/naser-rezayi-89774723b_threading-multithreading-concurrency-activity-7251107808702545920-ogFo?utm_source=share&utm_medium=member_desktop
 * 
Here you have a chill example of "condition variables"!
The code creates a thread that simulates a short delay (2 milliseconds),
then sets a flag (ready) to true and notifies the main thread to wake it up.
The main thread waits for this condition to be signaled before proceeding,
ensuring that it only continues after the worker thread has completed its task.
This is a typical use case for condition variables to synchronize threads in C++.*/
