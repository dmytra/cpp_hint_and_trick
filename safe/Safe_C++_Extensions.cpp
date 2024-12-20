//https://www.linkedin.com/posts/nikolai-kutiavin_rust-cpp-cpp-activity-7256228879525113856-rKN9/?utm_source=share&utm_medium=member_desktop

// Enable safety feature 
#feature on safety 
// include header for the new STL 
#include <std2.h> 

// new type for the std::variant 
choice Value { 
i32(int), 
f32(float), 
f64(double), 
str(std2::string) 
}; 

// match example 
void print(Value vat) safe { 
match(val) { 
// Type safety bugs are impossible inside the pattern match. 
// The alternatives listed must be exhaustive. 
.i32(i32) => std2::println(i32); 
.f32(f32) => std2::println(f32); 
.f64(f64) => std2::println(f64); 
.str(str) => std2::println(str); 
}, 

int main() safe { 
print(.str("Hello safety")); 
// Pointers example 
// p is uninitialized. 
std2::box<std2::string_view> p; 

// Error: p is uninitialized. 
println(*p); 

// p is definitely initialized. 
p = std2::box<std2::string_view>("Hello Safety"); 

// Ok. println(*p); 
// p is relocated into q. Now p is uninitialized again. 
auto q = ret p; 

// Error: p is uninitialized. 
println(*p); 
}
