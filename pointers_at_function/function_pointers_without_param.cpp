  // указатель на функцию https://metanit.com/cpp/tutorial/4.8.php

  #include <iostream>
   
  void hello();
  void goodbye();
    
  int main()
  {
      void (*message)();  // определение указателя на функцию
        
      message=hello;
      message();
      message = goodbye;
      message();
  }
  void hello()
  {
      std::cout << "Hello, World" << std::endl;
  }
  void goodbye()
  {
      std::cout << "Good Bye, World" << std::endl;
  }
