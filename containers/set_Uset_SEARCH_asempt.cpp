 #include <iostream>
 #include <set>

#include <unordered_set>

// https://t.me/easy_c_plus/194
// Какая сложность поиска в set и unordered_set ?
 
// Контейнеры set и unordered_set представляют собой различные структуры данных, каждая из которых имеет свои особенности по скорости выполнения основных операций, включая поиск. Вот как работают эти контейнеры и какова сложность их операций поиска:

 int main() {
     std::set<int> mySet = {5, 3, 9, 1};
     auto search = mySet.find(3);
     if (search != mySet.end()) {
         std::cout << "Found " << *search << std::endl;
     } else {
         std::cout << "Not found" << std::endl;
     }
     
     std::unordered_set<int> mySetu = {5, 235,2,45,34,6343, 9, 1};
     auto searchU = mySetu.find(3);
     if (searchU != mySetu.end()) {
         std::cout << "Found " << *searchU << std::endl;
     } else {
         std::cout << "Not found" << std::endl;
     }
     {
         auto searchU = mySetu.find(5);
         if (searchU != mySetu.end()) {
             std::cout << "Found " << *searchU << std::endl;
         } else {
             std::cout << "Not found" << std::endl;
         }
     }
     
     return 0;
 }

 

