#include <iostream>
#include <thread>

int main()
{
    std::thread t([](){
        std::cout << "thread function\n";
    });
    std::cout << "main thread\n";
    t.join();
    return 0;
}

// link https://www.bogotobogo.com/cplusplus/C11/3_C11_Threading_Lambda_Functions.php
