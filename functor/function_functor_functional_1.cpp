// Полиморфная обёртка функции
//https://www.youtube.com/watch?v=Bm2jmUxkUVw&list=PLQOaTSbfxUtBm7DxblJZShqBQnBAVzlXX&index=94

#include <iostream>
#include <functional>

// std::function

void Foo()
{
std::cout << "foo()" << std::endl;
}

int main()
{
	std::function<void()> f;
	f = Foo;
	f();	
	
	return 0;
}
