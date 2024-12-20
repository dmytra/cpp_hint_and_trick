// class_Overloading.cpp

#include <iostream>

/*
https://t.me/easy_c_plus/742
 🟠Перегрузка
 Одна и та же функция имеет несколько вариантов с разными параметрами.
 Реализуется в одном и том же классе (или в глобальной области).
 Не требует использования ключевого слова virtual.

 */


// Перегрузка функций

// Перегруженные функции для сложения двух чисел разных типов
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Перегрузки методов класса

class Print {
public:
    void display(int i) {
        std::cout << "Integer: " << i << std::endl;
    }

    void display(double f) {
        std::cout << "Double: " << f << std::endl;
    }

    void display(const std::string& s) {
        std::cout << "String: " << s << std::endl;
    }
};


int main() {
    
    // Перегрузка функций
    
    std::cout << add(3, 4) << std::endl;    // Вызов int add(int, int)
    std::cout << add(3.5, 4.5) << std::endl; // Вызов double add(double, double)
    
    // Перегрузки методов класса
    Print printer;
    printer.display(5);          // Вызов display(int)
    printer.display(3.14);       // Вызов display(double)
    printer.display("Hello");    // Вызов display(std::string)
    
    return 0;
}

