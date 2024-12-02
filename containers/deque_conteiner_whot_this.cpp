#include <iostream>
#include <deque>

/*
 Что такое deque ?
 https://t.me/easy_c_plus/122
 std::deque (double-ended queue) — это контейнер в стандартной библиотеке C++, который предоставляет возможность эффективного добавления и удаления элементов как в начале, так и в конце. В отличие от std::vector, который оптимизирован для добавления и удаления элементов только с конца, std::deque позволяет выполнять эти операции с обеих сторон.
 */
int main() {
    std::deque<int> dq;

    // Добавление элементов в конец
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    // Добавление элементов в начало
    dq.push_front(0);
    dq.push_front(-1);

    // Вывод элементов
    for (int num : dq) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Вывод: -1 0 1 2 3

    // Удаление элементов из конца и начала
    dq.pop_back();
    dq.pop_front();

    // Вывод элементов после удаления
    for (int num : dq) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Вывод: 0 1 2

    return 0;
}

