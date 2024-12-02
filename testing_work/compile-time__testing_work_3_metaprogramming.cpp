// compile-time__testing_work_3_metaprogramming.cpp
// https://t.me/easy_c_plus/671
// Как проверять что все работает в compile-time?
// Можно проверять корректность выполнения операций на этапе компиляции, используя различные подходы, такие как статические утверждения (assertions) с помощью ключевого слова static_assert, использование constexpr, а также метапрограммирование на основе шаблонов.

#include <iostream>

// Пример метапрограммирования
template<int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    constexpr int result = Factorial<5>::value;
    static_assert(result == 120, "Factorial of 5 must be 120");

    std::cout << "Factorial of 5 is " << result << std::endl;

    return 0;
}

