// https://www.linkedin.com/posts/eduardo-david-gómez-saldias-4bbab0210_cpp-cplusplus-moderncpp-activity-7259349953477558272-tB2T/?utm_source=share&utm_medium=member_desktop

// https://godbolt.org/z/bqWhE9Mqd

// only c++ -std=c++23

// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines

#include <print>
#include <variant>
#include <cstdint>

struct Foo {
    uint8_t num{};
    void print() { std::println("Foo {}", num);}
};
struct Bar {
    uint16_t num{};
    void print() { std::println("Bar {}", num);}
};
struct Baz {
    uint32_t num{};
    void print() { std::println("Baz {}", num);}
};

int main() {
  std::variant<Foo, Bar, Baz> v{Foo{10}}; // initialize variant with Foo type
  std::visit([](auto& inner){ inner.print(); }, v); // prints Foo 10
  
  v = Bar{20}; // change inner value of variant to Bar{}
  std::visit([](auto& inner){ inner.print(); }, v); // prints Bar 20

  v = Baz{30}; // change inner value of variant to Baz{}
  std::visit([](auto& inner){ inner.print(); }, v); // prints Baz 30

  return 0;

  // https://godbolt.org/z/bqWhE9Mqd

  
//#include <stdint.h>
//#include <stdio.h>
//
//typedef struct { uint8_t num; } foo_t;
//typedef struct { uint16_t num; } bar_t;
//typedef struct { uint32_t num; } baz_t;
//
//typedef enum { tag_foo, tag_bar, tag_baz, } tag_e;
//
//typedef struct {
//    tag_e tag;
//    union {
//        foo_t foo;
//        bar_t bar;
//        baz_t baz;
//    }; // anonymous unions available since c11
//} tagged_union_t;
//
//// manually check for the tag of the tagged union and perform different actions
//void tagged_union_print(tagged_union_t *self) {
//    switch(self->tag) {
//        case tag_foo: printf("foo %i\n", self->foo.num); break;
//        case tag_bar: printf("bar %i\n", self->bar.num); break;
//        case tag_baz: printf("baz %i\n", self->baz.num); break;
//    }
//}
//
//int main(void) {
//    tagged_union_t tu = { .tag = tag_foo, .foo = {.num = 10} };
//    tagged_union_print(&tu); // prints foo 10
//
//    tu.tag = tag_bar; // manually change the type tag
//    tu.bar = (bar_t){ .num = 20}; // update the inner value
//    tagged_union_print(&tu); // prints:  bar 20
//  
//    tu.tag = tag_baz; // manually change the type tag
//    tu.baz = (baz_t){ .num = 30}; // update the inner value
//    tagged_union_print(&tu); // prints:  baz 30
//
//    return 0;
//}}
