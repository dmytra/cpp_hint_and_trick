#include <iostream>


// https://t.me/easy_c_plus/739
// В чем разница между struct и class?

/*
 🟠Доступ по умолчанию
 struct: Все члены (переменные и методы) по умолчанию имеют публичный (public) доступ.
 class: Все члены (переменные и методы) по умолчанию имеют приватный (private) доступ.
 
 🟠Назначение и семантика
 struct: Исторически использовались для простых данных (Plain Old Data, POD). В современной практике struct часто используется для агрегирования данных, без сложной логики.
 class: Используется для создания более сложных объектов с инкапсуляцией данных и логикой, используя принципы объектно-ориентированного программирования (ООП).
 
 🟠Наследование
 В struct и class поддерживается наследование. Однако доступ по умолчанию для наследования тоже различается:
 struct: Наследование по умолчанию является публичным.
 class: Наследование по умолчанию является приватным.
 */



struct MyStruct {
    int x; // Публичный по умолчанию
};

class MyClass {
    int x; // Приватный по умолчанию
};


struct Point {
    int x;
    int y;

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};



class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return 3.14159 * radius * radius;
    }

    void setRadius(double r) {
        radius = r;
    }
};

struct BaseStruct {};
struct DerivedStruct : BaseStruct {}; // public наследование

class BaseClass {};
class DerivedClass : BaseClass {}; // private наследование


template <typename T>
struct MyTemplateStruct {
    T value;
};

template <typename T>
class MyTemplateClass {
    T value;
};

int main() {

    Point p = {10, 20};
    p.move(5, 5);
    std::cout << "Point: (" << p.x << ", " << p.y << ")" << std::endl; // Вывод: Point: (15, 25)

    Circle c(10);
    std::cout << "Area: " << c.getArea() << std::endl; // Вывод: Area: 314.159
    c.setRadius(5);
    std::cout << "New Area: " << c.getArea() << std::endl; // Вывод: New Area: 78.53975
    
    /*
     Point: (15, 25)
     Area: 314.159
     New Area: 78.5397
     */
    
    return 0;
}


