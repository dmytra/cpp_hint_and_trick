 // without synchro thread

 /*

 #include <iostream>
 #include <thread>
 #include <chrono>

 // https://habr.com/ru/articles/738250/

 void sleep(int duration) {
     // simulate expensive operation
     std::this_thread::sleep_for(std::chrono::seconds(duration));
 }

 int main() {
     std::cout << "starting first thread...\n";
     std::thread th1(sleep, 1);

     std::cout << "starting second thread...\n";
     std::thread th2(sleep, 2);

     std::cout << "waiting for threads to finish...\n";

     th1.join();
     std::cout << "the first thread finished\n";

     th2.join();
     std::cout << "the second thread finished\n";

     std::cout << "done\n";

     return 0;
 }
 */


 // with synchro thread


 #include <iostream>
 #include <thread>
 #include <chrono>
 #include <mutex>

 std::mutex mtx;

 void func(int a) {
     mtx.lock();
     for (int i = 0; i < 3; i++) {
         std::cout << a + i;
         std::this_thread::sleep_for(std::chrono::seconds(1));
         std::cout << " ";
     }
     std::cout << "\n";
     mtx.unlock();
 }

 int main() {

     std::thread th1(func, 1);
     std::thread th2(func, 4);

     th1.join();
     th2.join();

     return 0;
 }

