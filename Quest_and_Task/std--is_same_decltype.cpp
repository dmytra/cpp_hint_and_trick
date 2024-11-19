#include <iostream>
#include <type_traits>

// https://t.me/cpp_problems_lib/799
// https://cplusplus.com/reference/type_traits/

 int main()
 {
 int i, &j = i;
  [=]
     {
         std::cout << std::is_same<decltype((j)), int>::value
         << std::is_same<decltype(((j))), int&>::value
         << std::is_same<decltype((((j)))), int const&>::value
         << std::is_same<decltype(((((j))))), int&&>::value
         << std::is_same<decltype((((((j)))))), int const&&>::value << "\n";
     }();
     
 return 0;
 }


