    #include <iostream>
    #include <thread>
    #include <mutex>

    std::mutex mtx;

    void printThreadId(int id) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread ID: " << id << std::endl;
    }

    int main() {
        std::thread t1(printThreadId, 1);
        std::thread t2(printThreadId, 2);

        t1.join();
        t2.join();

        return 0;
    }
    
/*

 Какие есть виды mutex в стандартной библиотеке? 
https://t.me/easy_c_plus/406


➕ `std::mutex`: базовый мьютекс для синхронизации потоков.

➕ `std::recursive_mutex`: позволяет одному потоку несколько раз захватывать мьютекс.
➕ `std::timed_mutex`: предоставляет методы для попытки захвата мьютекса с таймаутом.

➕ `std::recursive_timed_mutex`: комбинирует рекурсивный мьютекс с возможностью таймаута.

➕ `std::shared_mutex`: позволяет разделяемый доступ для чтения и эксклюзивный доступ для записи (доступен с C++17).


    #include <iostream>
    #include <thread>
    #include <mutex>

    std::recursive_mutex recMtx;

    void recursiveFunction(int count) {
        if (count < 0) return;

        recMtx.lock();
        std::cout << "Count: " << count << std::endl;
        recursiveFunction(count - 1);
        recMtx.unlock();
    }

    int main() {
        std::thread t1(recursiveFunction, 5);
        t1.join();

        return 0;
    }
    



    #include <iostream>
    #include <thread>
    #include <mutex>
    #include <chrono>

    std::timed_mutex tMtx;

    void tryLockForExample() {
        if (tMtx.try_lock_for(std::chrono::seconds(1))) {
            std::cout << "Lock acquired" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            tMtx.unlock();
        } else {
            std::cout << "Timeout acquiring lock" << std::endl;
        }
    }

    int main() {
        std::thread t1(tryLockForExample);
        std::thread t2(tryLockForExample);

        t1.join();
        t2.join();

        return 0;
    }
    




*/

