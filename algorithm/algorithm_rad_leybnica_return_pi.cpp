#include <iostream>
#include <iomanip>
using namespace std;

// https://ru.stackoverflow.com/questions/839646/%D0%9A%D0%B0%D0%BA-%D0%B2%D1%8B%D0%B2%D0%B5%D1%81%D1%82%D0%B8-%D1%87%D0%B8%D1%81%D0%BB%D0%BE-%D0%9F%D0%B8-%D0%B4%D0%BE-%D0%BE%D0%BF%D1%80%D0%B5%D0%B4%D0%B5%D0%BB%D0%B5%D0%BD%D0%BD%D0%BE%D0%B3%D0%BE-%D0%B7%D0%BD%D0%B0%D0%BA%D0%B0
     
// clang++ -std=c++17 

int main()
{    
    double pi{};
    int j = 1;
    const int prec = 32;
    for (int i = 1; i < 500000; ++i) {  // бесконечный ряд
        pi += (double)4 / j;
        j += 2;
        pi -= (double)4 / j;
        j += 2;
    }
    cout << setprecision(prec) << pi;
    return 0;
}
