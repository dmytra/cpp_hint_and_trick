#include <type_traits>
#include <iostream>
#include <string>

// https://t.me/cpp_problems_lib/803

template<typename T>
int func()
{
    if constexpr (std::is_same_v<T, int>) {
        return 0;
    } else {
        return std::string{};
    }
}

int main()
{
std::cout << func<int>();
}
//No viable conversion from returned value of type 'std::string' (aka 'basic_string<char, char_traits<char>, allocator<char> >') to function return type 'int'

