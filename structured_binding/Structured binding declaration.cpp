#include <format>
#include <map>
#include <tuple>
#include <fstream>
#include <iostream>
// https://godbolt.org/z/G4nr7z8j1

int main() {
  // usage for array
  const std::array<int, 4> arr = {1, 2, 3, 4};
  auto [arr1, arr2, arr3, arr4] = arr;
  std::cout << std::format("{} {} {} {}\n", arr1, arr2, arr3, arr4); // prints: 1 2 3 4

  // usage for std::map container
  const auto ids = std::map<std::string_view, int> {
    {"First" , 1},
    {"Second", 2},
    {"Third" , 3},
  };
  // decompose as a const reference to avoid making unnecessary copies
  for (const auto& [key, value] : ids)
    std::cout << std::format("{} {}", key, value) << ", "; // prints: First 1, Second 2, Third 3,
  std::cout << "\n";

  // usage for function return value
  auto get_data = []() -> std::pair<int, std::string_view> {
    return {42, "foo"};
  };
  const auto& [num, str] = get_data();
  std::cout << std::format("num: {} str: {}\n", num, str); // prints: num: 42 str: foo

  // usage for tuple
  auto [f1, f2 ] = std::tuple{1.0f, 2.0f};

  // usage with tuple inside for loop
  // read a file line by line and stop on line 10 by creating a filestream, string and line counter
  // then read each line of filestream into string and increment line counter each iteration until line 10 is reachedd
  for(auto [i, line, file] = std::tuple{1, std::string{}, std::ifstream{"lines.txt"}}; std::getline(file, line), i <= 10; ++i) {
    std::cout << line << "\n"; // prints: <line content>
  }
  return 0;
}


/*
#include <iostream>
#include <format>
#include <map>
#include <tuple>
#include <fstream>
// https://en.cppreference.com/w/cpp/language/structured_binding
//
// https://www.linkedin.com/posts/eduardo-david-gómez-saldias-4bbab0210_cpp-cplusplus-moderncpp-activity-7270361296590499840-DMtV/?utm_source=share&utm_medium=member_desktop
int main() {
    // structured binding with array
    const std::array<int, 4> arr = {1, 2, 3, 4};
    auto [arr1, arr2, arr3, arr4] = arr;
    std::cout << std::format("{} {} {} {}\n", arrl, arr2, arr3, arr4);
    // prints: 1 2 3 4
    
    // structured binding with std::map container inside range-based for loop
    const auto ids = std::map<std::string_yiew, int> {
        {"First" , 1},
        {"Second", 2},
        {"Third" , 3},
    };
        // decompose as a const reference to avoid making unnecessary copies
    for (const auto& [key, value] : ids) {
        std::cout << std::format("Il {}", key, value) << " "; // prints: First 1, Second 2, Third 3,
    }
    
    // structured binding with function return value
    auto get_data = []() -> std::pair<int, std::string_view> {
        return {42, "foo"};
    };
    const auto& [num, str] = get_data();
    std::cout << std::format("num: str: fl\n", num, str); // prints: num: 42 str: foo
    // structured binding with tuple
    auto [f1, f2 ] = std::tuple{1.0f, 2.0f};
    
    // structured binding with tuple inside for loop
    // read a file line by line and stop on line 10 by creating a filestream, string and line counter
    // then read each line of filestream into string and increment line counter each iteration until line 10 is reachedd
    for(auto [i, line, file] = std::tuple{1, std::string{}, std::ifstream{"lines.txt"}};
    std::getline(file, line), i <= 10; ++i) std::cout << line << "\n"; // prints: <line content>
}
return 0;
}
*/

