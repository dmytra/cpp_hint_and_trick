// https://t.me/easy_c_plus/163
// \(O(1)\).
// Как удалить элемент из vector за константное время, если не важен порядок ?

#include <iostream>
#include <vector>

template<typename T>
void removeUnordered(std::vector<T>& vec, std::size_t index) {
    if (index < vec.size()) {
        vec[index] = std::move(vec.back());  // Перемещаем последний элемент на место удаляемого
        vec.pop_back();                      // Удаляем последний элемент
    }
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::cout << "Исходный вектор: ";
    for (int i : v) std::cout << i << " ";
    std::cout << "\n";

    // Удаляем элемент по индексу 2 (элемент 3)
    removeUnordered(v, 2);

    std::cout << "Вектор после удаления: ";
    for (int i : v) std::cout << i << " ";
    std::cout << "\n";

    return 0;
}

