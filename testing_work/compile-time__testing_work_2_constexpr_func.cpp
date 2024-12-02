// compile-time__testing_work_2_constexpr_func.cpp
// https://t.me/easy_c_plus/671
// Как проверять что все работает в compile-time?
// Можно проверять корректность выполнения операций на этапе компиляции, используя различные подходы, такие как статические утверждения (assertions) с помощью ключевого слова static_assert, использование constexpr, а также метапрограммирование на основе шаблонов.

#include <iostream>

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    constexpr int result = factorial(5); // Если ошибка, компилятор сообщит об этом

    static_assert(result == 120, "Factorial of 5 must be 120"); // Проверка значения

    std::cout << "Factorial of 5 is " << result << std::endl;

    return 0;
}



