// Какая сложность удаления в list и vector по итератору ?
// https://t.me/easy_c_plus/173
//
/*
 спользование std::list предпочтительнее, когда часто требуется удалять элементы из середины списка, так как это не влияет на производительность.

std::vector более подходит для случаев, когда операции вставки и удаления преимущественно происходят в конце контейнера, или когда важен быстрый доступ к элементам по индексу.
 */

#include <iostream>
#include <list>
#include <vector>

int main() {
    std::list<int> mylist = {10, 20, 30, 40, 50};
    auto it_list = std::next(mylist.begin(), 2); // Итератор на третий элемент
    mylist.erase(it_list); // Удаление элемента '30'

    std::vector<int> myvector = {10, 20, 30, 40, 50};
    auto it_vector = std::next(myvector.begin(), 2); // Итератор на третий элемент
    myvector.erase(it_vector); // Удаление элемента '30', требует сдвига элементов '40' и '50'

    // Вывод оставшихся элементов в list
    std::cout << "List: ";
    for (int elem : mylist) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // Вывод оставшихся элементов в vector
    std::cout << "Vector: ";
    for (int elem : myvector) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    return 0;
}

