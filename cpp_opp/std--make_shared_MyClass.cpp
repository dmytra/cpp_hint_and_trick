#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : value(value) {
        std::cout << "MyClass создан с значением " << value << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass уничтожен" << std::endl;
    }
private:
    int value;
};

int main() {
    auto ptr = std::make_shared<MyClass>(42); // Создание shared_ptr с помощью make_shared
    // Использование ptr...
    return 0;
}
// https://t.me/easy_c_plus/573
//
// Зачем нужна функция make_shared? 
