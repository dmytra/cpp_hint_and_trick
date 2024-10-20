#include <cassert>
#include <thread>

int data = 0;

void producer() {
  data = 100;  // Write data
}

void consumer() {
  assert(data == 100);
}

int main() {
  std::thread t1(producer);
  std::thread t2(consumer);
  t1.join();
  t2.join();
  return 0;

//  https://www-freecodecamp-org.translate.goog/news/atomics-and-concurrency-in-cpp/?_x_tr_sl=en&_x_tr_tl=ru&_x_tr_hl=ru&_x_tr_pto=wapp
}
