#include <iostream>
#include <thread>
#include <vector>

/*
 ====== threads.push_back incrementCounter ====
 thread main j=0 thread inner i=0 ||
 thread main j=0 thread inner i=1 ||
 thread main j=0 thread inner i=2 ||
 thread main j=0 thread inner i=3 ||
 ====== threads.push_back incrementCounter ====
 thread main j=1 thread inner i=0 ||
 thread main j=1 thread inner i=1 ||
 thread main j=1 thread inner i=2 ||
 thread main j=1 thread inner i=3 ||
 ====== threads.push_back incrementCounter ====
 thread main j=2 thread inner i=0 ||
 thread main j=2 thread inner i=1 ||
 thread main j=2 thread inner i=2 ||
 thread main j=2 thread inner i=3 ||
 ====== threads.push_back incrementCounter ====
 */

void foo(int i,int j)
{
   std::cout << "thread main j=" << j << " thread inner i=" << i << " || \n" ;
}
 
void incrementCounter(int j) {
    for (int i = 0; i < 4; ++i) {
        std::this_thread::sleep_for(std::chrono::microseconds(500000));
        std::thread first (foo,i,j);
        if (first.joinable()) first.join();

        //std::cout << "foo: " << first.joinable() << std::boolalpha << '\n';
    }
}

int main()
{
    const int numThreads = 4; // Number of threads to create
    std::vector<std::thread> threads;
        
    // Launch multiple threads to increment the counter
    for (int i = 0; i < numThreads; ++i) {
        std::this_thread::sleep_for(std::chrono::microseconds(3000000));
        std::cout << "====== threads.push_back incrementCounter ====\n" ;
        threads.push_back(std::thread(incrementCounter, i));
    }
        
    // Watt for all threads to finish
    for (auto& thread : threads) {
        std::cout << "======= incrementCounter.join() ========\n" ;
        thread.join();
    }
    
    std::cout << "Final counter value: " << std::endl;
    
  return 0;
    
    // https://www.linkedin.com/posts/nikolai-kutiavin_multithreaded-multithreading-cpp-ugcPost-7257098270353641472-2S7G/?utm_source=share&utm_medium=member_desktop

    // link https://cplusplus.com/reference/thread/thread/
    
    //https://cplusplus.com/reference/thread/thread/joinable/
}
