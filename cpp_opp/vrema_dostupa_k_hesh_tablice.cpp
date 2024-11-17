//https://t.me/easy_c_plus/530

#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    static const int hashGroups = 10;
    std::vector<std::list<std::pair<int, std::string>>> table;

public:
    HashTable() {
        table.resize(hashGroups);
    }

    int hashFunction(int key) {
        return key % hashGroups;
    }

    void insertItem(int key, std::string value) {
        int hashValue = hashFunction(key);
        table[hashValue].emplace_back(key, value);
    }

    void displayTable() {
        for (int i = 0; i < hashGroups; i++) {
            if (!table[i].empty()) {
                std::cout << "Group " << i << ": ";
                for (auto& pair : table[i]) {
                    std::cout << "[" << pair.first << ": " << pair.second << "] ";
                }
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    HashTable ht;
    ht.insertItem(1, "one");
    ht.insertItem(2, "two");
    ht.insertItem(11, "eleven"); // Коллизия с ключом 1

    ht.displayTable();
    // Вывод:
    // Group 1: [1: one] [11: eleven] 
    // Group 2: [2: two] 

    return 0;
}

