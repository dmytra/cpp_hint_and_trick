// Полиморфная обёртка функции
//https://www.youtube.com/watch?v=Bm2jmUxkUVw&list=PLQOaTSbfxUtBm7DxblJZShqBQnBAVzlXX&index=94

#include <iostream>
#include <functional>

// std::function

void Foo()
{
    std::cout << "foo()" << std::endl;
}

void Boo()
{
    std::cout << "Boo()" << std::endl;
}

int Sum(int a, int b)
{
    std::cout << "Summ = " << a + b << std::endl;
return a+b;
}

int main()
{
    std::function<void()> f;
    f = Foo;
    f();
    f = Boo;
    f();

    std::function<int(int,int)> fff;
    fff = Sum;
    int result = fff(22,44);

    std::cout << result << std::endl;

    
    return 0;
}
