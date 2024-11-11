#include <array>
#include <iostream>
 #include <string_view>
 #include <tuple>
 #include <type_traits>


// https://ravesli.com/urok-7-samye-rasprostranennye-problemy-s-s-resheniya/


/*
 hello 3 6
 3
 Program ended with exit code: 0
 */

 namespace a::b::c
 {
 inline constexpr std::string_view str{ "hello" };
 }

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
 {
 return { sizeof...(T), (args + ...) };
 }

int main()
 {
 auto [iNumbers, iSum]{ sum(1, 2, 3) };
 std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';

 std::array arr{ 1, 2, 3 };

 std::cout << std::size(arr) << '\n';

 return 0;
 }

