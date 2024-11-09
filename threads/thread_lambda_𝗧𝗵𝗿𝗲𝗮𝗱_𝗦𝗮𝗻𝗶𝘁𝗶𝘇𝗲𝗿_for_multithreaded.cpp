#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

// https://www.linkedin.com/posts/nikolai-kutiavin_multithreaded-multithreading-cpp-ugcPost-7257098270353641472-2S7G/?utm_source=share&utm_medium=member_desktop

int main() {
    bool ready = false;
    std::condition_variable condition;
    std::mutex mtx;
    std::thread t1([&]() {
        std::this_thread::sleep_for(std::chrono::microseconds(2'000));
        std::unique_lock<std::mutex> lock(mtx);
        ready = true;
        lock.unlock();
        condition.notify_one();
    });
    
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) { condition.wait(lock);
    }
    
    t1.join();
    return 0;
}
/*
 Writing Хэштег#multithreaded applications is easy: just create a thread, and you have it. But doing it 𝗰𝗼𝗿𝗿𝗲𝗰𝘁𝗹𝘆 is a hard job. Luckily, the C++ toolchain offers a way to detect such issues using 𝗧𝗵𝗿𝗲𝗮𝗱 𝗦𝗮𝗻𝗶𝘁𝗶𝘇𝗲𝗿. Just grab Clang and apply the flag 𝚏𝚜𝚊𝚗𝚒𝚝𝚒𝚣𝚎=𝚝𝚑𝚛𝚎𝚊𝚍 with 𝚐 -𝙾0 for debugging info and symbol data. Here’s how to detect threading issues:

 • Create a build type in your 𝙲𝙼𝚊𝚔𝚎 project,
 • Build your tests with the sanitizer flags,
 • Fix any problems found.

 Each threading violation leads to a core dump, so you can quickly trace root causes with GDB. Just don’t forget debugging symbols for libraries.

 In the example bellow a simple program with unsynchronized access to the variable `counter` and typical prompt from sanitizer. 
 */

