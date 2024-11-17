#include <iostream>
#include <type_traits>

int main() {
    std::cout << std::boolalpha;
    std::cout << "int: " << std::is_pointer<int>::value << std::endl;            // false
    std::cout << "int*: " << std::is_pointer<int*>::value << std::endl;          // true
    return 0;
}
//  Что такое тайп трейты?

// Тайп трейты (Type Traits) — это шаблоны в стандартной библиотеке C++, которые позволяют определять и изменять типы во время компиляции.
// https://t.me/easy_c_plus/497
