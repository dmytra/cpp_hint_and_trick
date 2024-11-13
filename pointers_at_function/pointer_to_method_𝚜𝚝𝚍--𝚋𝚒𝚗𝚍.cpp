#include <iostream>
#include <functional>

// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-pointers-stdbind-activity-7262101937850929153-eNb-/?utm_source=share&utm_medium=member_desktop

/*
A pointer to a method in C++ differs from an ordinary pointer to a function in one small detail—it requires a pointer to its object as the first parameter.
Using 𝚜𝚝𝚍::𝚋𝚒𝚗𝚍, you can convert it to a "normal" callable object.
*/

class MyClass {
public: void displayMessage(const std::string& message) {
    std::cout << "Message: " << message << std::endl;
    }
    
    int add(int a, int b) {
        return a + b;
    }
};

int main() {
    MyClass obj;
    
    // Pointer to member function
    void (MyClass::*displayPtr)(const std::string&) = &MyClass::displayMessage;

    // Calling member function using pointer-to-member
    (obj.*displayPtr)("Hello, using pointer to member function,");

    // Using std::bind to bind 'this' (obj) to the member function
    auto boundDisplay = std::bind(displayPtr, &obj, std::placeholders::_1);
        
    // Call the bound function with just the remaining argument
    boundDisplay("Hello, using std::bind!");
        
    // Another example: Binding 'add' method with 'std::bind'
    int (MyClass::*addPtr)(int, int) = &MyClass::add;
    auto boundAdd = std::bind(addPtr, &obj, std::placeholders::_1,
        std::placeholders::_2);
    
    // Call the bound add function
    int result = boundAdd(5, 10);
    std::cout << "Result of addition: " << result << std::endl;
        
    return 0;
}

