#include <iostream>
#include <thread>
#include <mutex>


// https://t.me/easy_c_plus/404

std::mutex mtx;

void sharedFunction() {
    std::lock_guard<std::mutex> lock(mtx);
    // Доступ к общим данным
    std::cout << "Thread " << std::this_thread::get_id() << " is running\n";
}

int main() {
    std::thread t1(sharedFunction);
    std::thread t2(sharedFunction);

    t1.join();
    t2.join();

    return 0;
}


/*

Чтобы избежать проблем с использованием std::mutex как локальной переменной, делайте его глобальным, статическим, членом класса или используйте умные указатели. Это гарантирует, что мьютекс будет существовать на протяжении всего времени, когда он необходим для синхронизации, и предотвратит неопределенное поведение.

#include <iostream>
#include <thread>
#include <mutex>

class SharedResource {
private:
    std::mutex mtx;
    int data;

public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        ++data;
        std::cout << "Data: " << data << " from thread " << std::this_thread::get_id() << "\n";
    }
};

int main() {
    SharedResource resource;

    std::thread t1(&SharedResource::increment, &resource);
    std::thread t2(&SharedResource::increment, &resource);

    t1.join();
    t2.join();

    return 0;
}



#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

void sharedFunction(std::shared_ptr<std::mutex> mtx) {
    std::lock_guard<std::mutex> lock(*mtx);
    // Доступ к общим данным
    std::cout << "Thread " << std::this_thread::get_id() << " is running\n";
}

int main() {
    auto mtx = std::make_shared<std::mutex>();

    std::thread t1(sharedFunction, mtx);
    std::thread t2(sharedFunction, mtx);

    t1.join();
    t2.join();

    return 0;
}



*/
