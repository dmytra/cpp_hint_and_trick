// compile-time__testing_work_1_static_assert.cpp
// https://t.me/easy_c_plus/671
// Как проверять что все работает в compile-time?
// Можно проверять корректность выполнения операций на этапе компиляции, используя различные подходы, такие как статические утверждения (assertions) с помощью ключевого слова static_assert, использование constexpr, а также метапрограммирование на основе шаблонов.

#include <type_traits>

// Пример с static_assert
constexpr int square(int x) {
    return x * x;
}

int main() {
    constexpr int value = square(5);
    static_assert(value == 25, "Value must be 25"); // Проверка на этапе компиляции

    // Пример с проверкой типа
    static_assert(std::is_integral<int>::value, "int must be integral type");

    return 0;
}



