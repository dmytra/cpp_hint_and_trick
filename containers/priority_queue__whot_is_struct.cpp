#include <iostream>
#include <stack>
#include <queue>
  
/*
 priority_queue в C++ реализован на основе структуры данных, называемой куча (heap).
 https://t.me/easy_c_plus/243
 https://t.me/easy_c_plus/236
       //
       //priority_queue в C++ реализован на основе структуры данных, называемой куча (heap). В большинстве случаев используется бинарная куча, которая может быть либо минимальной кучей, либо максимальной кучей. В стандартной библиотеке C++ priority_queue по умолчанию представляет собой максимальную кучу, то есть элемент с наивысшим приоритетом находится на вершине кучи.

1⃣ Удобство: priority_queue предоставляет простой интерфейс для работы с приоритетами, позволяя добавлять и извлекать элементы с наивысшим приоритетом.

2⃣ Эффективность: Использование кучи гарантирует эффективное выполнение операций вставки и удаления.

3⃣ Гибкость: Возможность использовать различные компараторы для реализации как максимальной, так и минимальной кучи.

priority_queue в C++ построен на основе структуры данных "куча". Это обеспечивает эффективные операции вставки и удаления элементов с наивысшим приоритетом, 

➕ push(): Вставляет новый элемент в кучу.

➕ pop(): Удаляет элемент с наивысшим приоритетом (вершину кучи).

➕ top(): Возвращает элемент с наивысшим приоритетом без удаления его из кучи.


*/
int main() {

    { // https://t.me/easy_c_plus/236
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
    }
    
    { // https://t.me/easy_c_plus/236
            // Создание min-heap с помощью std::greater<int>
            std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

            // Добавление элементов
            min_pq.push(10);
            min_pq.push(30);
            min_pq.push(20);
            min_pq.push(5);

            // Извлечение элементов
            while (!min_pq.empty()) {
                std::cout << min_pq.top() << " "; // Вывод: 5 10 20 30
                min_pq.pop();
            }
    }
    
    // ============= https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
    {
        std::cout << "\n";
        int arr[6] = { 10, 2, 4, 8, 6, 9 };

        // defining priority queue
        std::priority_queue<int> pq;

        // printing array
        std::cout << "Array: ";
        for (auto i : arr) {
            std::cout << i << ' ';
        }
            std::cout << std::endl;
        // pushing array sequentially one by one
        for (int i = 0; i < 6; i++) {
            pq.push(arr[i]);
        }

        // printing priority queue
        std::cout << "Priority Queue: ";
        while (!pq.empty()) {
            std::cout << pq.top() << ' ';
            pq.pop();
        }
    }
        
    return 0;
}

