#include <iostream>
// вычислять значения на этапе компиляции?
// https://t.me/easy_c_plus/668
// Вычисление значений на этапе компиляции (compile-time) можно осуществлять с помощью функции constexpr. Функции, объявленные как constexpr, позволяют компилятору вычислять их значения во время компиляции, если аргументы, переданные этим функциям, также являются константными выражениями. Это помогает оптимизировать код и избежать избыточных вычислений во время выполнения программы.

// Определение constexpr функции
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    // Вычисление значения на этапе компиляции
    constexpr int result = factorial(5);

    std::cout << "Factorial of 5 is " << result << std::endl; // Вывод: Factorial of 5 is 120

    // Пример использования constexpr переменной
    constexpr int size = 10;
    int arr[size] = {0}; // Массив с размером, вычисленным на этапе компиляции

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

