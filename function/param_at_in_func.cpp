#include <cstdarg>
#include <iostream>

// https://t.me/easy_c_plus/683
// передачa параметров в функции?

// Почему ссылка безопаснее для защиты от изменений?
// https://t.me/easy_c_plus/687

void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int number = va_arg(args, int);
        std::cout << number << " ";
    }
    va_end(args);
    std::cout << std::endl;
}

int main() {
    printNumbers(3, 1, 2, 3); // Вывод: 1 2 3
    return 0;
}

/*
 void increment(int value) {
     value++;
 }

 int main() {
     int a = 5;
     increment(a);
     std::cout << a << std::endl; // Вывод: 5 (исходное значение не изменилось)
     return 0;
 }

 
 void increment(int& value) {
     value++;
 }

 int main() {
     int a = 5;
     increment(a);
     std::cout << a << std::endl; // Вывод: 6 (исходное значение изменилось)
     return 0;
 }

 
 void increment(int* value) {
     (*value)++;
 }

 int main() {
     int a = 5;
     increment(&a);
     std::cout << a << std::endl; // Вывод: 6 (исходное значение изменилось)
     return 0;
 }

 
 void print(const std::string& str) {
     std::cout << str << std::endl;
 }

 int main() {
     std::string text = "Hello, world!";
     print(text); // Передача без копирования, текст не изменится
     return 0;
 }

 
 */

/*
 void printValue(const int& value) {
     std::cout << value << std::endl;
     // value++; // Ошибка компиляции: попытка изменить константный параметр
 }

 int main() {
     int a = 5;
     printValue(a); // Передача по константной ссылке
     return 0;
 }
 

 
 void printString(const std::string& str) {
     std::cout << str << std::endl;
 }

 int main() {
     std::string text = "Hello, world!";
     printString(text); // Эффективная передача без копирования
     return 0;
 }

 
 class MyClass {
 public:
     void display() const {
         std::cout << "MyClass object" << std::endl;
     }
 };

 void processObject(const MyClass& obj) {
     obj.display();
     // obj.someMethod(); // Ошибка компиляции, если someMethod() не является const
 }

 int main() {
     MyClass myObject;
     processObject(myObject);
     return 0;
 }

 
 
 */
