 #include <iostream>
 // Что такое полиморфизм?
 // Одно из фундаментальных понятий объектно-ориентированного программирования (ООП), которое позволяет объектам разных классов быть обработанными единообразно
 // polimorfizm_static_.cpp

 // https://t.me/easy_c_plus/674
 // Полиморфизм времени компиляции (статический полиморфизм)

 // Пример перегрузки функции
  int add(int a, int b) {
      return a + b;
  }

  double add(double a, double b) {
      return a + b;
  }

  // Пример перегрузки оператора
  class Complex {
  public:
      double real, imag;

      Complex(double r, double i) : real(r), imag(i) {}

      // Перегрузка оператора +
      Complex operator+(const Complex& other) const {
          return Complex(real + other.real, imag + other.imag);
      }
  };



int main() {
 
    std::cout << "Полиморфизм времени компиляции (статический полиморфизм) " << std::endl;

    return 0;
}

