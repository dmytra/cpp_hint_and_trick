#include <iostream>

//  В каком порядке элементы списка инициализируются в конструкторе после двоеточия?
//  https://t.me/easy_c_plus/735

/*
Порядок инициализации элементов списка инициализации конструктора (initializer list)
 определяется порядком объявления членов класса, а не порядком, указанным в списке инициализации.
 Это важно понимать, так как неправильный порядок может привести к неожиданным ошибкам,
 особенно при инициализации зависимых членов.
 */

class MyClass {
private:
    int a;
    int b;
    int c;

public:
    MyClass(int x, int y, int z) : c(z), b(y), a(x) {
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    }
};

int main() {
    MyClass obj(1, 2, 3); // a: 1, b: 2, c: 3
    return 0;
}

/*

DONT CORRECT

class MyClass {
private:
    int a;
    int& ref;

public:
    MyClass(int x) : ref(a), a(x) { // Неправильный порядок: ref инициализируется до a
        std::cout << "a: " << a << ", ref: " << ref << std::endl;
    }
};


 */

