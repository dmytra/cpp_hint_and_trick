#include <iostream>

void stackFunction() {
    int stackArray[1000]; // Массив на стеке
    // Работа с массивом
}

void heapFunction() {
    int* heapArray = new int[1000]; // Массив в куче
    // Работа с массивом
    delete[] heapArray; // Освобождение памяти
}

int main() {
    stackFunction(); // Быстрая работа со стеком
    heapFunction();  // Медленная работа с кучей
    return 0;
}
// https://t.me/easy_c_plus/532
