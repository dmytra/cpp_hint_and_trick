#include <iostream>
#include <string>

class MyClass {

//     https://t.me/easy_c_plus/617
public:
    MyClass() {
        data = new int[10];  // Выделение ресурсов
        throw std::runtime_error("Ошибка в конструкторе!");  // Исключение
    }
    ~MyClass() {
        delete[] data;  // Деструктор не будет вызван
    }
private:
    int* data;
};

int main() {
    try {
        MyClass obj;  // Попытка создать объект
    } catch (const std::exception& e) {
        std::cerr << "Поймано исключение: " << e.what() << std::endl;
    }
    // В этот момент память, выделенная для data, утечет
    return 0;
}


