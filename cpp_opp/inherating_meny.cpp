#include <iostream>

class Base1 {
public:
    Base1() { std::cout << "Base1 Constructor" << std::endl; }
    virtual ~Base1() { std::cout << "Base1 Destructor" << std::endl; }
};

class Base2 {
public:
    Base2() { std::cout << "Base2 Constructor" << std::endl; }
    virtual ~Base2() { std::cout << "Base2 Destructor" << std::endl; }
};

class Derived : public Base1, public Base2 {
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
 
 
Множественное наследование

При множественном наследовании деструкторы также вызываются в обратном порядке создания объектов, то есть сначала вызываются деструкторы производного класса, а затем деструкторы базовых классов в порядке, обратном их перечислению в списке наследования.   */
