#include <iostream>
#include <thread>
#include <future>
#include <iomanip>

// https://www.linkedin.com/posts/naser-rezayi-89774723b_hello-friend-how-can-we-get-a-functions-activity-7258000301343862784-xIVi/?utm_source=share&utm_medium=member_desktop

// How can we get a functions "return" in a thread???

double CalculatePi(int terms)
{
    double result = 0.0;
    for (int i = 0; i < terms; i++)
    {
        result += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
    }
        return result * 4;
}
    
int main()
{
    std::promise<double> promise;
    auto do_calculation = [&](int terms) {
        promise. set_value(CalculatePi(terms));
    };
    
    std::thread tl(do_calculation, 1000'000'000);
    std::future<double> future = promise.get_future();
    std::cout << std::setprecision(25) << future.get() << std::endl;
    tl.join();
    
return 0;
}


