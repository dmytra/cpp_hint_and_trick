#include <iostream>
#include <vector>
/*
  clang++ -std=c++2a *.cpp
 Demonstrating '[[likely]]':
 1 is positive..
 2 is positive..
 3 is positive..
 -1 is non-positive.
 5 is positive..
 Demonstrating '[[assume]]':
 Processing value: 20
 
 ====
 
 https://www.linkedin.com/posts/nikolai-kutiavin_cplusplus-codeoptimization-performance-activity-7270014014120775680-rrra/?utm_source=share&utm_medium=member_desktop
 ====
 
 Programs can often be optimized through better algorithms, more efficient data structures, or by leveraging C++
  attributes. Some of these attributes can help the compiler generate
 more efficient code. Two such attributes that can improve performance
 are:
 * likely: Indicates to the compiler which conditional branch is more likely
  to occur. This can help the compiler optimize for the most frequent case.
 * assume: Specifies certain conditions or assumptions, which can be used by
  the compiler to generate more optimized code.
 The example below demonstrates how these attributes can be applied to improve performance:
 */
// Function to demonstrate '[[likely]]' attribute
void checkNumbers(const std::vector<int>& numbers) {
    for (const auto& num : numbers) {
        if (num > 0) [[likely]] {
            std::cout << num << " is positive.." << std::endl;
        } else {
            std::cout << num << " is non-positive." << std::endl;
        }
    }
}
// Function to demonstrate '[[assume]]' attribute
void process(int value) {
    // Tell the compiler we assume 'value' is always greater than 10
    [[assume(value > 10)]];
    std::cout << "Processing value: " << value << std::endl;
    
    // The compiler can optimize knowing 'value > 10' is always true
    if (value > 50) {
        std::cout << "Value is significantly large." << std::endl;
    }
}
int main() {
    std::vector<int> numbers = {1, 2, 3, -1, 5};
    
    std::cout << "Demonstrating '[[likely]]':" << std::endl;
    checkNumbers(numbers);

    std::cout << "Demonstrating '[[assume]]':" << std::endl;
    int value = 20;
    // Ensure value > 10 for valid '[[assume]]'
    process(value);

    return 0;
}

