  #include <iostream>

 // https://t.me/easy_c_plus/699
 // константные методы?
  

 class MyClass {
 public:
     MyClass(int v) : value(v) {}

     int getValue() const { // Константный метод
         return value;
     }

     void setValue(int newValue) { // Неконстантный метод
         value = newValue;
     }

 private:
     int value;
 };

 int main() {
     MyClass obj(10);

     std::cout << "Value: " << obj.getValue() << std::endl; // Вывод: 10

     obj.setValue(20);
     std::cout << "New value: " << obj.getValue() << std::endl; // Вывод: 20

     // Константный объект
     const MyClass constObj(30);
     std::cout << "Const object value: " << constObj.getValue() << std::endl; // Вывод: 30

     // constObj.setValue(40); // Ошибка: setValue не может быть вызван для константного объекта

     return 0;
 }


 /*
  const MyClass constObj(30);
  constObj.getValue(); // Допустимо: getValue — константный метод
  // constObj.setValue(40); // Ошибка: setValue — неконстантный метод

  
  🟠Гарантия неизменности
  Константные методы гарантируют, что состояние объекта не будет изменено. Это полезно для методов, которые предназначены только для чтения данных объекта, например, методы доступа (геттеры).
  🟠Безопасность и семантика
  Константные методы помогают лучше понимать код и повышают его безопасность, так как ясно видно, какие методы могут изменять состояние объекта, а какие нет.
  🟠Работа с константными объектами
  Константные методы можно вызывать на константных объектах и через константные ссылки или указатели. Это позволяет использовать объекты в контексте, где важно гарантировать их неизменность.
 class MyClass {
 public:
     int getValue() const; // Константный метод
     void setValue(int newValue); // Неконстантный метод

 private:
     int value;
 };

 // Определение константного метода
 int MyClass::getValue() const {
     return value; // Допустимо: метод не изменяет состояние объекта
 }

 // Определение неконстантного метода
 void MyClass::setValue(int newValue) {
     value = newValue; // Допустимо: метод изменяет состояние объекта
 }

 */

