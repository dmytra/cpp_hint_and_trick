#include <iostream>
#include <atomic>
#include <cassert>
#include <thread>

int data = 0;
std::atomic<bool> ready(false);

void producer() {
  std::cout << "\n" << data;
	
  data = 100;
  ready.store(true, std::memory_order_relaxed);  // Set flag
}

void consumer() {
  std::cout << "\n" << data;
  
  while (!ready.load(std::memory_order_relaxed)) 
	  ;
  assert(data == 100);
}

int main() {
  std::thread t1(producer);
  std::thread t2(consumer);
  t1.join();
  t2.join();

  std::cout << "\n FIN: " << data << "\n";
  
  return 0;
// https://www-freecodecamp-org.translate.goog/news/atomics-and-concurrency-in-cpp/?_x_tr_sl=en&_x_tr_tl=ru&_x_tr_hl=ru&_x_tr_pto=wapp
}
