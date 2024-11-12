  // указатель на функцию с парвметрвми https://metanit.com/cpp/tutorial/4.8.php
  #include <iostream>
    
  int sum(int, int);
  int subtract(int, int);
     
  int main()
  {
      int a{10};
      int b{5};
      int (*operation)(int, int) {sum};   // указатель operation указывает на функцию sum
      int result = operation(a, b);
      // result = (*operation)(a, b); // альтернативный вариант
      std::cout << "result = " << result << std::endl;     // result = 15
         
      operation = subtract;   // указатель operation указывает на функцию subtract
      result = operation(a, b);
      std::cout << "result = " << result << std::endl;     // result = 5
  }
  int sum(int x, int y)
  {
      return x+y;
  }
  int subtract(int x, int y)
  {
      return x-y;
  }
