// class_Overriding.cpp

 

/*
https://t.me/easy_c_plus/742
Переопределение происходит, когда метод базового класса определяется повторно в производном классе с той же сигнатурой (именем и параметрами). Это позволяет производному классу предоставлять свою собственную реализацию метода, которая заменяет реализацию базового класса при вызове метода через объект производного класса.
 */


#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }

    virtual ~Base() = default; // Виртуальный деструктор для правильного удаления производных объектов
};

class Derived : public Base {
public:
    void show() override { // Переопределение метода show()
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show(); // Вызов метода show() из класса Derived
    delete basePtr;
    return 0;
}

