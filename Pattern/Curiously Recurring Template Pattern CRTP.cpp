#include <iostream>
//https://t.me/easy_c_plus/397
// Базовый шаблонный класс, параметризированный производным классом
template <typename Derived>
class Base {
public:
    void interface() {
        // Вызов метода реализации из производного класса
        static_cast<Derived*>(this)->implementation();
    }

    // Метод реализации по умолчанию
    void implementation() {
        std::cout << "Base implementation" << std::endl;
    }
};

// Производный класс, передающий себя как параметр базовому классу
class Derived : public Base<Derived> {
public:
    // Переопределение метода реализации
    void implementation() {
        std::cout << "Derived implementation" << std::endl;
    }
};

int main() {
    Derived d;
    d.interface(); // Вызывает Derived::implementation
    return 0;
}


/*
 *
 * Идиома статического полиморфизма в C++ называется Curiously Recurring Template Pattern (CRTP). Этот паттерн позволяет осуществлять полиморфизм во время компиляции, а не во время выполнения, как это происходит с использованием виртуальных функций. CRTP используется для реализации функций, которые могут быть переопределены в производных классах, без использования виртуальных функций, что позволяет избежать их накладных расходов и добиться большей производительности.
 *
 * 
    template <typename Derived>
    class Interface {
    public:
        void execute() {
            static_cast<Derived*>(this)->execute_impl();
        }
    };

    class Implementation : public Interface<Implementation> {
    public:
        void execute_impl() {
            std::cout << "Executing implementation" << std::endl;
        }
    };
    
*/

/*
    template <typename Derived>
    class Logging {
    public:
        void log(const std::string& message) {
            std::cout << "Log: " << message << std::endl;
        }
    };

    class Application : public Logging<Application> {
    public:
        void run() {
            log("Application is running");
        }
    };
    
 
   */

