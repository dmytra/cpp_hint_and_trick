//https://www.bogotobogo.com/cplusplus/C11/3_C11_Threading_Lambda_Functions.php

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

int main()
{
    // vector container stores threads
    std::vector<std::thread> workers;
    for (int i = 0; i < 9; i++) {
        workers.push_back(std::thread([]() 
        {
            std::cout << "thread function\n";
        }));
    }
    std::cout << "main thread\n";

    // Looping every thread via for_each
    // The 3rd argument assigns a task
    // It tells the compiler we're using lambda ([])
    // The lambda function takes its argument as a reference to a thread, t
    // Then, joins one by one, and this works like barrier
    std::for_each(workers.begin(), workers.end(), [](std::thread &t) 
    {
        t.join();
    });

    return 0;
}
