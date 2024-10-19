// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  // do stuff...
   std::this_thread::sleep_for(std::chrono::microseconds(1000000));
   std::cout << "void foo()  completed.\n";
 
}

void bar(int x)
{
  // do stuff...
   std::this_thread::sleep_for(std::chrono::microseconds(7000000));
   std::cout << "void bar(int x) completed.\n" << x << "\n";
 
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,1110);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;

  // link https://cplusplus.com/reference/thread/thread/
}
