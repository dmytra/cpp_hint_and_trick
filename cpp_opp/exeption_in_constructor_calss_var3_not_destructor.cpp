 #include <iostream>
 #include <stdexcept>

// https://t.me/easy_c_plus/199

 class Resource {
 public:
     Resource() { std::cout << "Resource acquired.\n"; }
     ~Resource() { std::cout << "Resource released.\n"; }
 };

 class Test {
     Resource res;

 public:
     Test() {
         std::cout << "Test constructor start.\n";
         throw std::runtime_error("Exception thrown in constructor");
         std::cout << "Test constructor end.\n"; // Этот код никогда не выполнится
     }
     ~Test() {
         std::cout << "Test destructor.\n"; // Не будет вызван
     }
 };

 int main() {
     try {
         Test t;
     } catch (const std::exception& e) {
         std::cout << "Exception caught: " << e.what() << std::endl;
     }
     return 0;
 }
