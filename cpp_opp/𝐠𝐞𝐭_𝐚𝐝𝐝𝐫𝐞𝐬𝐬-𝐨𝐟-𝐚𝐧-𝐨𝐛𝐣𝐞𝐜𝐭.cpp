#include <iostream>
#include <memory> // For std::addressof

// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-cpptips-moderncpp-activity-7275057319724367872-hKd9/?utm_source=share&utm_medium=member_desktop
// 𝐇𝐨𝐰 𝐭𝐨 𝐠𝐞𝐭 𝐭𝐡𝐞 𝐚𝐝𝐝𝐫𝐞𝐬𝐬 𝐨𝐟 𝐚𝐧 𝐨𝐛𝐣𝐞𝐜𝐭? The answer seems simple: use & before the object. 
// 𝑠𝑡𝑑::𝑎𝑑𝑑𝑟𝑒𝑠𝑠𝑜𝑓

// Normal struct
struct NormalStruct {
    int value;
};

// Class with a custom operator&
class CustomAddress {
public:
    char padding = 0;
    int value;

    CustomAddress(int val) : value(val) {}

    // Custom operator& that returns a different type
    int* operator&() {
        std::cout << "Custom operator& called!" << std::endl;
        return &(this->value); // For simplicity, returning this
    }
};

int main() {
    // Normal struct example
    NormalStruct ns{42};
    std::cout << "NormalStruct address using & : " << &ns << '\n';
    std::cout << "NormalStruct address using std::addressof : " << std::addressof(ns) << '\n';

    // Class with custom operator&
    CustomAddress obj(100);

    // Using custom operator&
    int* customAddr = &obj; // Calls CustomAddress::operator&
    std::cout << "Address from custom operator& : " << customAddr << '\n';

    // Using std::addressof to bypass the custom operator&
    CustomAddress* realAddr = std::addressof(obj);
    std::cout << "Actual address using std::addressof : " << realAddr << '\n';

    return 0;
}


