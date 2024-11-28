#include <iostream>
#include <vector>

// https://t.me/easy_c_plus/176
// Что за ключевое слово noexcept ?

void noThrowFunction() noexcept {
    std::cout << "This function does not throw exceptions.\n";
}

void mayThrowFunction() {
    std::vector<int> v(1000000);
    std::cout << "This function might throw exceptions.\n";
}

int main() {
    std::cout << "noThrowFunction noexcept: " << noexcept(noThrowFunction()) << std::endl;
    std::cout << "mayThrowFunction noexcept: " << noexcept(mayThrowFunction()) << std::endl;
    return 0;
}

