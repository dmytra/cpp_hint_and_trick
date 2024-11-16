#include <iostream>
#include <memory>

// https://t.me/easy_c_plus/388<D-c>


/*
 Вместо виртуальных конструкторов, в C++ используется паттерн "Фабрика" (Factory Pattern) для создания объектов полиморфным образом: 
 */

class Base {
public:
    virtual void display() const = 0; // Чисто виртуальная функция

    // Фабричный метод
    static std::unique_ptr<Base> create();
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived display" << std::endl;
    }
};

//std::unique_ptr<Base> Base::create() {
//    return std::make_unique<Derived>();
//}

int main() {
    auto obj = Base::create();
    obj->display(); // Вызовет Derived::display
    return 0;
}

