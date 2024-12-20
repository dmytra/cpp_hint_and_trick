// Что такое функции обратного вызова?
// https://t.me/easy_c_plus/745
// callback_function_on_c.cpp

/*
 Это функции, которые передаются как аргументы другим функциям, чтобы быть вызванными в определенный момент. Это важный механизм в программировании, который позволяет реализовывать гибкие и модульные решения, особенно в контексте асинхронного программирования, обработчиков событий и многопоточности.
 
 🟠Передача как параметр
 Функции обратного вызова передаются как параметры другим функциям.
 🟠Вызов в определенный момент
 Они вызываются внутри функции, которая их получила, в определенный момент времени или по определенному условию.
 🟠Гибкость и расширяемость
 Использование функций обратного вызова позволяет легко изменять поведение программы без необходимости изменения основной функции.

 🟠Пример на С
 В языке C функции обратного вызова обычно реализуются с использованием указателей на функции.
 */

#include <stdio.h>

// Объявление функции обратного вызова
void callback_function(int value) {
    printf("Callback called with value: %d\n", value);
}

// Функция, принимающая указатель на функцию в качестве параметра
void process_value(int value, void (*callback)(int)) {
    // Некоторая обработка
    value *= 2;

    // Вызов функции обратного вызова
    callback(value);
}

int main() {
    int x = 5;
    // Передача функции обратного вызова
    process_value(x, callback_function);
    return 0;
}

