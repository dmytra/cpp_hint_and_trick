// Полиморфная обёртка функции
//https://www.youtube.com/watch?v=Bm2jmUxkUVw&list=PLQOaTSbfxUtBm7DxblJZShqBQnBAVzlXX&index=94

#include <iostream>
#include <vector>
#include <functional>

// std::function

void Foo(int a)
{
    if (a > 10 && a < 44)
    {
        std::cout << "foo()\t" << a << std::endl;
    }
}

void Boo(int a)
{
    if (a*2 < 44)
    {
        std::cout << "boo()\t" << a*2 << std::endl;
    }
}

int Sum(int a, int b)
{
    std::cout << "Summ = " << a+ b << std::endl;
    return a+b;
}

void DoWork(std::vector<int> &vc, std::function<void(int)> f)
{
    for (auto el : vc)
    {
        f(el);
    }
}


int main()
{
    std::vector<int> vc = { 1,23,4,34,4,3,4,26,456,5467, 55,23,45,567,435,45,3453,45353,4,5,74,34,42,24, 24,32,32,3,2,3,4,2,4,2423,23,2,4,244,3,5,3,65465,44};

    DoWork(vc, Foo);
    DoWork(vc, Boo);

    
    return 0;
}
