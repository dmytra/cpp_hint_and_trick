// 𝐬𝐢𝐦𝐩𝐥𝐞-𝐥𝐨𝐨𝐤𝐢𝐧𝐠 𝐜𝐨𝐧𝐜𝐞𝐩𝐭 𝐨𝐟 𝑚𝑢𝑡𝑒𝑥
//
// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-cppmultithreading-moderncpp-activity-7275419630163116032-Ytpx/?utm_source=share&utm_medium=member_desktop
// https://lnkd.in/e_ZNU-8H
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// Function demonstrating std::lock_guard
void lockGuardExample(int threadId, std::mutex& mtx) {
    // Automatically locks the mutex when created, unlocks when destroyed
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread " << threadId << " using std::lock_guard to lock mtx\n";
    // Mutex is automatically released at the end of this scope
}

// Function demonstrating std::unique_lock
void uniqueLockExample(int threadId, std::mutex& mtx) {
    // Provides more flexibility than std::lock_guard
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Thread " << threadId << " using std::unique_lock to lock mtx\n";

    // Unlock manually if needed
    lock.unlock();
    std::cout << "Thread " << threadId << " unlocked mtx manually\n";

    // Lock again manually
    lock.lock();
    std::cout << "Thread " << threadId << " locked mtx again\n";

    // Mutex will be released automatically at the end of this scope
}

// Function demonstrating std::scoped_lock for deadlock avoidance
void scopedLockExample(int threadId, std::mutex& mtx1, std::mutex& mtx2) {
    // Simultaneously locks multiple mutexes without risk of deadlock
    std::scoped_lock lock(mtx1, mtx2);
    std::cout << "Thread " << threadId << " using std::scoped_lock to lock mtx1 and mtx2\n";
}

int main() {
    // Define mutexes locally in main
    std::mutex mtx1, mtx2;

    std::vector<std::thread> threads;

    // Launch threads to demonstrate std::lock_guard
    threads.emplace_back(lockGuardExample, 1, std::ref(mtx1));

    // Launch threads to demonstrate std::unique_lock
    threads.emplace_back(uniqueLockExample, 2, std::ref(mtx1));

    // Launch threads to demonstrate std::scoped_lock
    threads.emplace_back(scopedLockExample, 3, std::ref(mtx1), std::ref(mtx2));

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}


