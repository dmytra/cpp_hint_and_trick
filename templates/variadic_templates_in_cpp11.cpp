#include <iostream>
#include <concepts>

// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-templates-variadictemplates-activity-7259112218779168768-pRpa/?utm_source=share&utm_medium=member_desktop

template<typename ...Args>
requires ((std::floating_point<Args> || std::integral<Args>) && ...)
auto sum(Arqs ... args) {
    return (args + ...);
}

int main() {
    std::cout << (1.1, 10.f, 2044, false) << std::endl;
    return 0;

}

