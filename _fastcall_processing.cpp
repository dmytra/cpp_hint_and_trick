#include <iostream>

// https://t.me/easy_c_plus/733
// Расскажите про ключевое слово _fastcall?

// Функция, использующая соглашение о вызове _fastcall
int __fastcall add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);
    std::cout << "Result: " << result << std::endl; // Вывод: Result: 8
    return 0;
}

/*
 #include <iostream>

 // Проверка платформы
 #ifdef _M_IX86 // Если используется компилятор для архитектуры x86
 int __fastcall add(int a, int b) {
     return a + b;
 }
 #else
 int add(int a, int b) {
     return a + b;
 }
 #endif

 int main() {
     int result = add(5, 3);
     std::cout << "Result: " << result << std::endl; // Вывод: Result: 8
     return 0;
 }

 */

