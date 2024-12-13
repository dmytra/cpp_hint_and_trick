 #include <iostream>
// https://t.me/cpp_interview_lib/552

/*
  Является ли тип std::list потокобезопасной (thread-safe) коллекцией?
 Нет, std::list в C++ не является потокобезопасной (thread-safe) коллекцией по умолчанию.
 */

#include <list>
#include <mutex>

class ThreadSafeList {
    private: std::list<int> data;
    mutable std::mutex mutex;
        
public:
    void push_back(int value) {
    std::lock_guard<std::mutex> lock(mutex);
    data.push_back(value);
}
    int front() const {
        std::lock_guard<std::mutex> lock(mutex);
        return data.front();
    }
    int back() const {
        std::lock_guard<std::mutex> lock(mutex);
        return data.back();
    }
};


int main() {
    ThreadSafeList tList;
    tList.push_back(12);
    tList.push_back(22);
    tList.push_back(32);

    std::cout << tList.front() << "\n";
    std::cout << tList.back() << "\n";
    std::cout << tList.front() << "\n";
    
    return 0;
}


