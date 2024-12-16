/*
 Назовите три краеугольных камня ООП?
 https://t.me/easy_c_plus/730
 */

#include <iostream>

// Инкапсуляция

class Account {
private:
    double balance;

public:
    Account(double initial_balance) : balance(initial_balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};


// Наследование
class Shape {
public:
    virtual double area() const = 0; // Чисто виртуальная функция
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};


// Полиморфизм
#include <iostream>
#include <vector>

void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
}

 

int main() {
// Инкапсуляция
    Account ac(20.6);
    std::cout << ac.getBalance() << " ";
 
    std::cout << "\n";
    
// Наследование
    Rectangle rec(232,23);
        std::cout << rec.area() << " ";
    
    std::cout << "\n";
    
// Полиморфизм
    Circle circle(5);
    Rectangle rectangle(4, 6);

    std::vector<Shape*> shapes = {&circle, &rectangle};

    for (const auto* shape : shapes) {
        printArea(*shape); // Полиморфный вызов
    }

    return 0;
}

