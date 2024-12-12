    #include <iostream>
    #include <unordered_set>

// unordered_set поиск - асимптотика
// https://t.me/easy_c_plus/114

    int main() {
        std::unordered_set<int> mySet;

        // Добавление элементов
        mySet.insert(1);
        mySet.insert(2);
        mySet.insert(3);

        // Поиск элемента
        if (mySet.find(2) != mySet.end()) {
            std::cout << "Element found" << std::endl;
        } else {
            std::cout << "Element not found" << std::endl;
        }

        return 0;
    }

