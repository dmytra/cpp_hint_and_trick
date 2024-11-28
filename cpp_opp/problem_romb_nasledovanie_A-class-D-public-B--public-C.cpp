#include <iostream>

// https://t.me/easy_c_plus/179
// "Что такое виртуальное наследования ? 
// Проблема алмаза

class A {
public:
    int value;
};

class B : virtual public A {
};

class C : virtual public A {
};

class D : public B, public C {
};

int main() {
    D d;
    d.value = 34534;
    std::cout << "Что такое виртуальное наследования ? class \n D.value= " << d.value << std::endl;
}

