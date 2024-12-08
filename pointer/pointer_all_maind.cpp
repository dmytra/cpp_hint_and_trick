  #include <iostream>

// https://t.me/easy_c_plus/117
// Что в себе хранит указатель ?
// Указатель (pointer) — это переменная, которая хранит адрес другой переменной в памяти. По сути, указатель "указывает" на местоположение другого значения.

   void func() {
    std::cout << "Hello, World!" << std::endl;
}

  int main() {
      
      void (*funcPtr)() = func;
      funcPtr(); // Вызов функции через указатель

      
      int value = 42;
      int* ptr = &value; // ptr хранит адрес переменной value

      std::cout << "Значение value: " << value << std::endl; // Вывод: 42
      std::cout << "Адрес value: " << &value << std::endl; // Вывод: Адрес переменной value
      std::cout << "Значение, на которое указывает ptr: " << *ptr << std::endl; // Вывод: 42
      std::cout << "Адрес, хранимый в ptr: " << ptr << std::endl; // Вывод: Адрес переменной value

      // Изменение значения через указатель
      {
      *ptr = 10;
      std::cout << "Новое значение value: " << value << std::endl; // Вывод: 10
      }

     //
     {
     int value = 42;
     int* ptr = &value;
     *ptr = 10; // Изменение значения value через указатель
     std::cout << "value значение value: " << value << std::endl;
     }

      // 2️⃣Адресные операции:
      //      ✅& оператор используется для получения адреса переменной.
      //      ✅* оператор используется для разыменования указателя.

     // Арифметика указателей:
     {
     int arr[] = {1, 2, 3, 4, 5};
     int* ptr = arr;
     std::cout << *(ptr + 1) << std::endl;
     }

     //
     {
     int value = 42;
     int* ptr = &value;
     std::cout << "42 значение value: " << value << std::endl;
     }


      return 0;
  }


