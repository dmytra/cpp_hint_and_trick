#include <iostream>
#include <stack>
#include <queue>
//https://t.me/easy_c_plus/239
/*
 stack и queue в C++ построены на основе контейнера deque по умолчанию. Это обеспечивает эффективные операции вставки и удаления элементов, а также предоставляет гибкость и простоту использования для реализации стека и очереди.
➕ push(): Добавить элемент на вершину стека.

➕ pop(): Удаляет элемент с наивысшим приоритетом (вершину кучи).

➕ top(): Возвращает элемент с наивысшим приоритетом без удаления его из кучи.

➕ empty(): Проверить, пуст ли стек.

➕ size(): Получить количество элементов в стеке.
В стандартной библиотеке C++ контейнеры stack и queue являются адаптерами контейнеров, что означает, что они предоставляют специфические интерфейсы (например, стек и очередь), используя другой контейнер в качестве базового для хранения элементов. В стандартной реализации C++ эти адаптеры могут использовать различные контейнеры, но по умолчанию они построены на основе deque (двусвязного списка).
 
 
 ============
 
 priority_queue в C++ реализован на основе структуры данных, называемой куча (heap).
 https://t.me/easy_c_plus/243
 https://t.me/easy_c_plus/236
*/
int main() {
    std::stack<int> s;

    // Добавление элементов
    s.push(1);
    s.push(2);
    s.push(3);

    // Извлечение элементов
    while (!s.empty()) {
        std::cout << s.top() << " "; // Вывод: 3 2 1
        s.pop();
    }
    
    // ============= https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
    std::cout << "\n";
    
    // Создание priority_queue, по умолчанию это max-heap
    
    std::priority_queue<int> pq;

    // Добавление элементов
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // Извлечение элементов
    while (!pq.empty()) {
        std::cout << pq.top() << " "; // Вывод: 30 20 10 5
        pq.pop();
    }

    return 0;
}
