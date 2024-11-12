  
 #include <iostream>

 // Вызов функции через указатель на функцию
 // https://ravesli.com/urok-104-ukazateli-na-funktsii/
 // https://metanit.com/cpp/tutorial/4.8.php
 // https://learnc.info/c/function_pointers.html

 int boo(int a)
 {
     return a;
 }
  
 int main()
 {
     int (*fcnPtr)(int) = boo; // присваиваем функцию boo() указателю fcnPtr
     (*fcnPtr)(7); // вызываем функцию boo(7), используя fcnPtr
  
     return 0;
 }
