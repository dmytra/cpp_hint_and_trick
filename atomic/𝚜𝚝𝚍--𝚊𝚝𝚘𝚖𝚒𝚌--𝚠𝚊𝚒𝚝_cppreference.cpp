#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
 
using namespace std::literals;
 
int main()
{
    std::atomic<bool> all_tasks_completed{false};
    std::atomic<unsigned> completion_count{};
    std::future<void> task_futures[16];
    std::atomic<unsigned> outstanding_task_count{16};
 
    // Spawn several tasks which take different amounts of
    // time, then decrement the outstanding task count.
    for (std::future<void>& task_future : task_futures)
        task_future = std::async([&]
        {
            // This sleep represents doing real work...
            std::this_thread::sleep_for(50ms);
 
            ++completion_count;
            --outstanding_task_count;
 
            // When the task count falls to zero, notify
            // the waiter (main thread in this case).
            if (outstanding_task_count.load() == 0)
            {
                all_tasks_completed = true;
                all_tasks_completed.notify_one();
            }
        });
 
    all_tasks_completed.wait(false);
 
    std::cout << "Tasks completed = " << completion_count.load() << '\n';
}

// https://stackoverflow.com/questions/76632690/how-to-update-clang-compiler-on-macos-to-clang-16-to-get-c23-functionality
//
// https://en.cppreference.com/w/cpp/atomic/atomic/wait
//
// sudo port install clang-16
// sudo port select --set clang mp-clang-16
// brew install llvm@16
