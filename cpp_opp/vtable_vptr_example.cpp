// Как работает виртуальность в C++? 
// https://t.me/easy_c_plus/386
// Виртуальная таблица (vtable) и указатель на виртуальную таблицу (vptr)  Как работает vtable и vptr:

 #include <iostream>

 class Base {
 public:
     virtual void display() const {
         std::cout << "Display from Base" << std::endl;
     }
     virtual void show() const {
         std::cout << "Show from Base" << std::endl;
     }
 };

 class Derived : public Base {
 public:
     void display() const override {
         std::cout << "Display from Derived" << std::endl;
     }
 };

 void callDisplay(const Base& obj) {
     obj.display();
 }


 int main() {
     Base* b = new Derived();
     b->display(); // Вызовет Derived::display() благодаря vtable
     b->show();    // Вызовет Base::show() поскольку она не переопределена

     delete b;

     Base bb;
     Derived d;

     callDisplay(bb); // Вызовет Base::display()
     callDisplay(d); // Вызовет Derived::display()



     return 0;
 }


 /*
 class Base {
 public:
     virtual void display() const {
         std::cout << "Display from Base" << std::endl;
     }
 };

 class Derived : public Base {
 public:
     void display() const override {
         std::cout << "Display from Derived" << std::endl;
     }
 };
 */

