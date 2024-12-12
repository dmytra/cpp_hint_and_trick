#include <iostream>

// https://t.me/easy_c_plus/109
// Что такое наследование ?

using namespace std;

// Базовый класс
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }
};

// Производный класс
class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark! Woof woof!" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Вызов метода базового класса
    myDog.bark(); // Вызов метода производного класса
    return 0;
}

