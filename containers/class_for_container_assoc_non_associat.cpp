#include <iostream>
#include <map>
// Что необходимо иметь классу, что бы использовать его в качестве ключа к ассоциативным контейнерам?
// https://t.me/easy_c_plus/643
class MyKey {
public:
    int value;
    
    MyKey(int v) : value(v) {}
    
    bool operator<(const MyKey& other) const {
        return value < other.value;
    }
};

int main() {
    std::map<MyKey, std::string> myMap;
    myMap[MyKey(1)] = "one";
    myMap[MyKey(2)] = "two";
    
    for (const auto& pair : myMap) {
        std::cout << pair.first.value << ": " << pair.second << std::endl;
    }
    
    return 0;
}

/*
 #include <iostream>
 #include <unordered_map>
 #include <functional>

 class MyKey {
 public:
     int value;
     
     MyKey(int v) : value(v) {}
     
     bool operator==(const MyKey& other) const {
         return value == other.value;
     }
 };

 namespace std {
     template <>
     struct hash<MyKey> {
         std::size_t operator()(const MyKey& k) const {
             return std::hash<int>()(k.value);
         }
     };
 }

 int main() {
     std::unordered_map<MyKey, std::string> myMap;
     myMap[MyKey(1)] = "one";
     myMap[MyKey(2)] = "two";
     
     for (const auto& pair : myMap) {
         std::cout << pair.first.value << ": " << pair.second << std::endl;
     }
     
     return 0;
 }

 */

