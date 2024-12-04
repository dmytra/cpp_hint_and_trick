#include <iostream>
#include <queue>

/*
 priority_queue_how_work.cpp
 Как работает priority_queue ?
 https://t.me/easy_c_plus/131
 
 priority_queue — это мощный инструмент для управления данными, когда доступ к наиболее значимым элементам должен быть быстрым и эффективным. Благодаря своей реализации на основе двоичной кучи, priority_queue обеспечивает быстрые операции вставки и удаления, что делает его идеальным выбором для многих задач, включая симуляции, планировщики задач, и алгоритмы, требующие частого доступа к элементам с наивысшим приоритетом.
 */
int main() {
    std::priority_queue<int> pq;

    // Добавление элементов
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Вывод элементов от наибольшего к наименьшему
    while (!pq.empty()) {
        std::cout << pq.top() << std::endl; // Печатает наивысший элемент
        pq.pop(); // Удаляет наивысший элемент
    }

    return 0;
}
