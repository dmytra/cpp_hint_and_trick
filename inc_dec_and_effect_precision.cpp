#include <iostream>

// Урок No43. Инкремент, декремент и побочные эффекты
// C++ ravesli.com

// Xcode - passed
// clang -std=c++17 dont work
// clang++ -std=c++17
// gcc -std=c++17 dont work
// g++ -std=c++17 dont work
// c++ -std=c++17 dont work

int add(int x, int y)
 {
 return x + y;
 }

 int main()
 {
 int x = 5;
 int value = add(x, ++x); // здесь 5 + 6 или 6 + 6? Это зависит от компилятора и от того, в каком порядке он будет обрабатывать аргументы функции

 std::cout << value << "\n"; // результатом может быть 11 или 12

     
 int z = 1;
 z = z++;
 std::cout << z;
 
     
// Урок No45. Операторы сравнения
     
 double d1(100 - 99.99); // должно быть 0.01
 double d2(10 - 9.99); // должно быть 0.01

std::cout << d1 << "\t" << d2 << "\n";
     // Xcode - passed      10.01    0.01   d1 > d2
     // clang -std=c++17 dont work
     // clang++ -std=c++17 - passed      10.01    0.01   d1 > d2
     // gcc -std=c++17 dont work
     // g++ -std=c++17 - passed      10.01    0.01   d1 > d2
     // c++ -std=c++17 - passed      10.01    0.01   d1 > d2
     
 if (d1 == d2)
 std::cout << "d1 == d2" << "\n";
 else if (d1 > d2)
 std::cout << "d1 > d2" << "\n";
 else if (d1 < d2)
 std::cout << "d1 < d2" << "\n";
     
 return 0;
 }

