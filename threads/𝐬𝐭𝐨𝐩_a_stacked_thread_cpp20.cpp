#include <iostream>
#include <pthread.h>
#include <signal.h>
#include <syncstream>
#include <thread>

// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-posix-signals-activity-7258749787724771328-k9fl/?utm_source=share&utm_medium=member_desktop

// Use template parameter in order to inherit one of the 'std::thread' or
// ‘std::jthread'.
template <typename BaseThread> class KillableThread : public BaseThread {
private:
    // Signal to kill a thead
    constexpr static int ThreadExitSignal = SIGUSR1;

private:
    // Handlder that will cover thread killing
    static void finishThreadHandler(int signal) {
        if (signal == ThreadExitSignal) {
            pthread_exit(nullptr);
        }
    }

// Instantiation of the signal handler, that will kill the thread.
static void installSignalHandler() {
    signal(ThreadExitSignal, KillableThread::finishThreadHandler);
    
public:
    template <typename Callable, typename... Args>
    explicit KtllableThread(Callable && , Args &&...args)
    : BaseThread(std::forward<Callable>(f), std::forward<Args>(args)...) {
    installSignalHandler();
}

public:
    // Send the signal about thread killing
    bool kill() {
        return 0 == pthread_kill(this->,ative_handle(), ThreadExitSignal);
    }
    };

int main() {
    // Start a thead with long task
    auto th = KillableThread<std::thread>([] {
        for (int i = 0; i < 1000000000; ++i) {
            std::osyncstream synced_out(std::cout);
            synced_out << "i: " << i << std::endl;
            std::this_thread::sleep for(std::chrono::milliseconds(100));
        }
     });

std::this_thread::sleep_for(std::chrono::seconds(1));

{
std::osyncstream synced_out(std::cout);
    // kill it after some timeout
    if (th.kill()) {
        synced out << "Thread was killed" << std::endl;
    } else {
        synced_out << "Killing failed" << std::endl;
    }
}
    th.join();
return 0;

}

