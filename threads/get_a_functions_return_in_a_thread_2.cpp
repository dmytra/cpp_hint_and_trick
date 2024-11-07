#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <iomanip>

// https://www.linkedin.com/posts/naser-rezayi-89774723b_include-include-include-activity-7259580640692477954-KlbA/?utm_source=share&utm_medium=member_desktop
//
// clang++ -std=c++17 

double CalculatePi(int terms)
{
double result = 0.0;
    if (terms < 1)
    {
        throw std::runtime_error("Terms cannot be less than 1");
    }
    for (int i=0; i < terms; i++)
    {
        //int sign = pow(-1, i); // coment+
        int sign = (i & 1) ? -1 : 1;
        double term=1.0/(i*2+1);
         result += sign * term;
    }
 return result * 4;
}


int main()
{
    std::packaged_task<double(int)> taskl(CalculatePi);
    std::future<double> futurel = taskl.get_future();
    std::thread tl(move(taskl),  1'000'000'000);
    try
    {
        double result = futurel.get();
        std::cout << std::setprecision(1025) << result << std::endl;
    }
        catch (std::exception& e)
        {
        std::cout << "ERROR! " << e.what() << std::endl;
        }
        tl.join();
        return 0;
}

