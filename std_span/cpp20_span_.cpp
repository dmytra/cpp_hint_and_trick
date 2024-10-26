#include <iostream> 
#include <span> 
#include <vector> 
#include <array> 

void print(std::span<const int> data) 
{ 
for (auto& item : data) 
{
std::cout << item << ' ';
}
std::cout << '\n'; 
}

int main() {

std::vector<int> vec{10, 20, 30}; 
int arr[]{4, 5, 6, 7, 8}; 
std::array<int, 8> stdArr{9, 10, 11, 12, 13, 14, 15, 16}; 
print(vec); 
print(arr); 
print(stdArr); 
// Demonstrates using std::span with std::vector 
// Demonstrates using std::span with C-style array 
// Demonstrates using std::span with std::array 

}			     	
//https://www.linkedin.com/posts/samira-mh_cpp-cplusplus-stdabrspan-activity-7256018908917190658-G2nR/?utm_source=share&utm_medium=member_desktop			 	



