#include <iostream>

// https://t.me/easy_c_plus/170
// Зачем компилятор помечает деструктор как noexcept ?

class SafeResource {
public:
    ~SafeResource() noexcept {
        // Код очистки, который не выбрасывает исключения
        std::cout << "Ресурс освобожден" << std::endl;
    }
};

int main() {
    
    SafeResource sR;
    
    std::cout << "pass \n";

    return 0;
}

