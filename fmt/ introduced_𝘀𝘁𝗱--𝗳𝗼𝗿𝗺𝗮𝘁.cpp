// using fmt::format 
// https://www.linkedin.com/posts/eduardo-david-g%C3%B3mez-saldias-4bbab0210_cpp-cplusplus-moderncpp-activity-7254386101681876994-cp0r?utm_source=share&utm_medium=member_desktop
//
#include <format>
#include <print>

struct Vec3 {
  int x, y, z;
};

template <>
struct std::formatter<Vec3> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const Vec3& self, std::format_context& ctx) const {
        return std::format_to(ctx.out(), "({}, {}, {})", self.x, self.y, self.z);
    }
};

int main() {
  std::println("My Vec3: {}", Vec3{1, 2, 3});
}
