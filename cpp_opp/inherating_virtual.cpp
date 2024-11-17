#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Intermediate1 : virtual public Base {
public:
    Intermediate1() { std::cout << "Intermediate1 Constructor" << std::endl; }
    virtual ~Intermediate1() { std::cout << "Intermediate1 Destructor" << std::endl; }
};

class Intermediate2 : virtual public Base {
public:
    Intermediate2() { std::cout << "Intermediate2 Constructor" << std::endl; }
    virtual ~Intermediate2() { std::cout << "Intermediate2 Destructor" << std::endl; }
};

class Derived : public Intermediate1, public Intermediate2 {
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
 
 
Виртуальное наследование

При виртуальном наследовании также вызываются деструкторы в обратном порядке создания объектов, но особенность заключается в том, что общий базовый класс уничтожается только один раз, независимо от количества наследников. */
