#include <iostream>
#include <memory>
//https://t.me/easy_c_plus/189
// Как работает счетчик ссылок в shared_ptr ?
int main() {
    auto sp1 = std::make_shared<int>(10); // Счетчик ссылок = 1
    {
        std::shared_ptr<int> sp2 = sp1; // Счетчик ссылок = 2
        std::cout << "Count after sp2 creation: " << sp2.use_count() << std::endl;
    } // Счетчик ссылок = 1, sp2 уничтожен
    std::cout << "Count after sp2 destruction: " << sp1.use_count() << std::endl;
}

