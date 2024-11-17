#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print_if_integral(T value) {
    std::cout << "Integral value: " << value << std::endl;
}

int main() {
    print_if_integral(5);       // Работает, так как 5 — целое число
    // print_if_integral(5.5);  // Ошибка компиляции, так как 5.5 — не целое число
    return 0;
}
//  Что такое тайп трейты?

// Тайп трейты (Type Traits) — это шаблоны в стандартной библиотеке C++, которые позволяют определять и изменять типы во время компиляции.
// https://t.me/easy_c_plus/497
