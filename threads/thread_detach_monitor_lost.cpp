#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
void pause_thread(int n) 
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}
 
int main() 
{
  std::cout << "Spawning and detaching 5 threads...\n";
  std::thread (pause_thread,1).detach();
  std::thread (pause_thread,2).detach();
  std::thread (pause_thread,3).detach();
  //
  std::thread (pause_thread,6).detach();
  std::cout << "Done spawning threads.\n";
  std::cout << "(the main thread will now pause for 4 seconds)\n";
  // give the detached threads time to finish (but not guaranteed!):
  pause_thread(4);
  std::cout << ">>>> thread #6 LOST. >>>> return 0 !!!\n\n";



  std::cout << "Spawning and detaching 8 threads...\n";
  std::thread (pause_thread,1).detach();
  std::thread (pause_thread,2).detach();
  std::thread (pause_thread,3).join();
  std::thread (pause_thread,4).detach();
  //
  std::thread (pause_thread,6).detach();
  std::thread (pause_thread,7).join();
  std::thread (pause_thread,8).detach();

  std::cout << "Done spawning threads.\n";
  std::cout << "(the main thread will now pause for 5 seconds)\n";
  // give the detached threads time to finish (but not guaranteed!):
  pause_thread(5);
  std::cout << ">>>> thread #8 LOST.  >>>> return 0 !!!\n";

  return 0;
}
//https://cplusplus.com/reference/thread/thread/detach/
