#include <iostream>
#include <string>
#include <set>
#include <unordered_set>

// https://t.me/easy_c_plus/379

/*
 ➕ Используйте `std::set`, когда нужно хранить уникальные элементы в отсортированном порядке и важны диапазонные операции.

 ➕ Используйте `std::unordered_set`, когда порядок не важен и требуется высокая производительность для операций поиска, вставки и удаления.
 
 В C++ контейнеры std::set и std::unordered_set используются для хранения уникальных элементов, но они имеют разные характеристики, которые делают их подходящими для различных сценариев. Давайте рассмотрим, когда использовать каждый из них.

 🤔 `std::set`

 std::set — это ассоциативный контейнер, который хранит уникальные элементы в отсортированном порядке. Он реализован как сбалансированное бинарное дерево (обычно красно-черное дерево), что определяет его характеристики.

 */

struct MyStruct {
    int id;
    std::string name;
    bool operator==(const MyStruct& other) const {
        return id == other.id && name == other.name;
    }
};

struct MyStructHash {
    std::size_t operator()(const MyStruct& s) const {
        return std::hash<int>()(s.id) ^ std::hash<std::string>()(s.name);
    }
};


int main() {
 
    std::unordered_set<MyStruct, MyStructHash> mySet;
    
    std::set<int> sortedSet = {5, 1, 3, 2, 4};
    for (int n : sortedSet) {
        std::cout << n << " "; // Вывод: 1 2 3 4 5
    }
    
    auto it = sortedSet.lower_bound(3); // Указатель на элемент >= 3
        
    std::cout << "\n" << *it;
    
    sortedSet.insert(6); // O(log n)
    sortedSet.erase(1);  // O(log n)
    auto found = sortedSet.find(4); // O(log n)
    
    std::unordered_set<int> hashSet = {5, 1, 3, 2, 4};
    for (int n : hashSet) {
        std::cout << n << " "; // Порядок не определен
    }
        
    hashSet.insert(6); // O(1)
    hashSet.erase(1);  // O(1)
    auto found2 = hashSet.find(4); // O(1)
    

    // ===========================
    //https://t.me/easy_c_plus/381
    
    int* ptr = new int(10); // Выделение памяти для одного целого числа
    delete ptr; // Удаление объекта и освобождение памяти
    
    int* arr = new int[10]; // Выделение памяти для массива из 10 целых чисел
    delete[] arr; // Удаление массива и освобождение памяти
    
        class MyClass {
        public:
            ~MyClass() {
                std::cout << "Destructor called!" << std::endl;
            }
        };

 
    MyClass* obj = new MyClass();
    delete obj; // Вызов деструктора
 
        
    int* ptr2 = new int(10);
    delete ptr2;
//    delete ptr2; // Ошибка: повторное удаление
    
    int* ptr3;
    //delete ptr3; // Ошибка: удаление неинициализированного указателя
    

    int* arr3 = new int[10];
    //delete arr3; // Ошибка: неправильное удаление массива
    

    
    
    
    return 0;
}


