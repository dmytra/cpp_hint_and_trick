#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

// https://stackoverflow-com.translate.goog/questions/74521674/why-mutex-lock-on-c-affects-multithreading-efficiency-so-badly?_x_tr_sl=en&_x_tr_tl=ru&_x_tr_hl=ru&_x_tr_pto=wapp

long double store;
std::mutex lock;

using ftype=std::function<long double(long int)>;
using loop_type=std::function<void(long int, long int, ftype)>;


///simple class to time the execution and print result.
struct time_n_print
{
  time_n_print() : 
    start(std::chrono::high_resolution_clock::now())
  {}
  
  ~time_n_print()
  {
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(elapsed);
    std::cout << "Elapsed(ms)=" << std::setw(7) << ms.count();
    std::cout << "; Result: " << (long int)(store);
  }
  std::chrono::high_resolution_clock::time_point start;
};//class time_n_print

///do long and pointless calculations which result in 1.0
long double slow(long int i)
{
    long double pi=3.1415926536;
    long double i_rad  = (long double)(i) * pi / 180;
    long double sin_i  = std::sin(i_rad);
    long double cos_i  = std::cos(i_rad);
    long double sin_sq = sin_i * sin_i;
    long double cos_sq = cos_i * cos_i;
    long double log_sin_sq = std::log(sin_sq);
    long double log_cos_sq = std::log(cos_sq);
    sin_sq = std::exp(log_sin_sq);
    cos_sq = std::exp(log_cos_sq);
    long double sum_sq = sin_sq + cos_sq;
    long double result = std::sqrt(sum_sq);
    return result;
}

///just return 1
long double fast(long int)
{
    return 1.0;
}

///sum everything up with mutex
void loop_guarded(long int a, long int b, ftype increment)
{
  for(long int i = a; i < b; ++i)
  {
    long double inc = increment(i);
    {
      std::lock_guard<std::mutex> guard(lock);
      store += inc;
    }
  }
}//loop_guarded

///sum everything up without locks
void loop_unguarded(long int a, long int b, ftype increment)
{
  for(long int i = a; i < b; ++i)
  {
    long double inc = increment(i);
    {
      store += inc;
    }
  }
}//loop_unguarded

//run calculations on multiple threads.
void run_calculations(int size, 
                      int nthreads, 
                loop_type loop, 
                    ftype increment)
{
  store = 0.0;
  std::vector<std::thread> tv;
  long a(0), b(0);
  for(int n = 0; n < nthreads; ++n)
  {
    a = b;
    b = n < nthreads - 1 ? a + size / nthreads : size;
    tv.push_back(std::thread(loop, a, b, increment));
  }
  //Wait, until all threads finish
  for(auto& t : tv)
  {
    t.join();
  }
}//run_calculations

int main()
{
  long int size = 10000000;
  {
    std::cout << "\n1 thread  - fast, unguarded : ";
    time_n_print t;
    run_calculations(size, 1, loop_unguarded, fast);
  }
  {
    std::cout << "\n1 thread  - fast, guarded   : ";
    time_n_print t;
    run_calculations(size, 1, loop_guarded, fast);
  }
  std::cout << std::endl;
  {
    std::cout << "\n1 thread  - slow, unguarded : ";
    time_n_print t;
    run_calculations(size, 1, loop_unguarded, slow);
  }
  {
    std::cout << "\n2 threads - slow, unguarded : ";
    time_n_print t;
    run_calculations(size, 2, loop_unguarded, slow);
  }
  {
    std::cout << "\n3 threads - slow, unguarded : ";
    time_n_print t;
    run_calculations(size, 3, loop_unguarded, slow);
  }
  {
    std::cout << "\n4 threads - slow, unguarded : ";
    time_n_print t;
    run_calculations(size, 4, loop_unguarded, slow);
  }
  std::cout << std::endl;
  {
    std::cout << "\n1 thread  - slow, guarded   : ";
    time_n_print t;
    run_calculations(size, 1, loop_guarded, slow);
  }
  {
    std::cout << "\n2 threads - slow, guarded   : ";
    time_n_print t;
    run_calculations(size, 2, loop_guarded, slow);
  }
  {
    std::cout << "\n3 threads - slow, guarded   : ";
    time_n_print t;
    run_calculations(size, 3, loop_guarded, slow);
  }
  {
    std::cout << "\n4 threads - slow, guarded   : ";
    time_n_print t;
    run_calculations(size, 4, loop_guarded, slow);
  }
  std::cout << std::endl;
  return 0;
}
