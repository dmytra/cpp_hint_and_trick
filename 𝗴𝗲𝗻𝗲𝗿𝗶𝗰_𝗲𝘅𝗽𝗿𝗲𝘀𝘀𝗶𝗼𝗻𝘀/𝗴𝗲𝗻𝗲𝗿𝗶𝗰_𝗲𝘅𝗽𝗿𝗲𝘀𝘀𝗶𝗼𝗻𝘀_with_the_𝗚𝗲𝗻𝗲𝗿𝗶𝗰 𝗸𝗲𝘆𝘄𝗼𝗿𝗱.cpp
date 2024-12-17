#include <stdint.h>
#include <stdio.h>

// https://www.linkedin.com/posts/eduardo-david-gómez-saldias-4bbab0210_cpp-c-cplusplus-activity-7274713691722240000-OLK-/?utm_source=share&utm_medium=member_desktop
// https://godbolt.org/z/cxj6qsdTT
/*
C11 introduced 𝗴𝗲𝗻𝗲𝗿𝗶𝗰 𝗲𝘅𝗽𝗿𝗲𝘀𝘀𝗶𝗼𝗻𝘀 with the _𝗚𝗲𝗻𝗲𝗿𝗶𝗰 𝗸𝗲𝘆𝘄𝗼𝗿𝗱, bringing a basic level of type-based polymorphism to the C programming language. While C lacks 𝗳𝘂𝗻𝗰𝘁𝗶𝗼𝗻 𝗼𝘃𝗲𝗿𝗹𝗼𝗮𝗱𝗶𝗻𝗴, a feature natively available in C++, this feature enables a similar behavior by dispatching the appropriate function based on the type of a variable 𝗮𝘁 𝗰𝗼𝗺𝗽𝗶𝗹𝗲 𝘁𝗶𝗺𝗲.
 */

typedef struct { uint32_t x, y; } vec2u32_t;
typedef struct { int32_t x, y; } vec2i32_t;
typedef struct { float x, y; } vec2f_t;

void vec2u32_add(vec2u32_t *self, uint32_t value) {
    self->x += value;
    self->y += value;
}
void vec2i32_add(vec2i32_t *self, int32_t value) {
    self->x += value;
    self->y += value;
}
void vec2f_add(vec2f_t *self, float value) {
    self->x += value;
    self->y += value;
}

#define vec2_print(SELF) \
  _Generic((SELF), \
    vec2u32_t: printf("[%u, %u]\n", SELF.x, SELF.y), \
    vec2i32_t: printf("[%i, %i]\n", SELF.x, SELF.y), \
    vec2f_t:   printf("[%f, %f]\n", SELF.x, SELF.y) \
  )

#define vec2_add(SELF, V) \
  _Generic((SELF), \
    vec2u32_t*: vec2u32_add, \
    vec2i32_t*: vec2i32_add, \
    vec2f_t*: vec2f_add \
  )(SELF, V)

int main(void) {
    vec2u32_t v1 = {10, 20};
    vec2_add(&v1, 5); // perfom "add" operation without type postfix
    vec2_print(v1); // prints: [15, 25]

    vec2i32_t v2 = {0, 0};
    vec2_add(&v2, -100); // perfom "add" operation without type postfix
    vec2_print(v2); // prints: [-100, -100]

    vec2f_t v3 = {0.1f, 0.2f};
    vec2_add(&v3, 0.5f); // perfom "add" operation without type postfix
    vec2_print(v3); // prints [0.6, 0.7]
}

/*
#include <print>
#include <format>

template <typename T> struct Vec2 {
    T x, y;
    void print() { std::println("[{}, {}]", x, y ); }
    void add(const T& num) { x += num; y += num; }
};

int main() {
  auto v1 = Vec2{10u, 20u};
  v1.add(5);
  v1.print(); // prints: [15, 25]

  auto v2 = Vec2{0, 0};
  v2.add(-100);
  v2.print(); // prints: [-100, -100]

  auto v3 = Vec2<float>{0.1f, 0.2f};
  v3.add(0.5f);
  v3.print(); // prints: [0.6, 0.7]
}

*/
