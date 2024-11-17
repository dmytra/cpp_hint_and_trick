#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor" << std::endl; }
    ~Derived() { std::cout << "Derived Destructor" << std::endl; }
};

int main() {
    Derived d;
    return 0;
}
// https://t.me/easy_c_plus/595
/*
 Какой порядок вызова деструкторов?
 сновное правило заключается в том, что деструкторы вызываются в обратном порядке создания объектов.
 
🚩Однократное наследование

При однократном наследовании деструкторы вызываются в обратном порядке иерархии наследования: сначала вызывается деструктор производного класса, затем деструктор базового класса.
   */
