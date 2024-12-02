#include <iostream>
#include <vector>

// https://t.me/easy_c_plus/665
// Почему vector будет плохо работать если унаследоваться от него?
// Не предусмотрено для наследования
// Закрытые и защищенные члены
// Нарушение инкапсуляции
// Проблемы с производительностью и безопасностью

class MyVector : public std::vector<int> {
public:
    void push_front(int value) {
        this->insert(this->begin(), value); // Попытка добавить элемент в начало
    }
};

int main() {
    MyVector mv;
    mv.push_back(1);
    mv.push_back(2);
    mv.push_front(0); // Вставка элемента в начало

    for (const auto& elem : mv) {
        std::cout << elem << " ";
    }
    return 0;
}

