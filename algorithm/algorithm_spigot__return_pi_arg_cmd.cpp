#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

// https://ru.stackoverflow.com/questions/839646/%D0%9A%D0%B0%D0%BA-%D0%B2%D1%8B%D0%B2%D0%B5%D1%81%D1%82%D0%B8-%D1%87%D0%B8%D1%81%D0%BB%D0%BE-%D0%9F%D0%B8-%D0%B4%D0%BE-%D0%BE%D0%BF%D1%80%D0%B5%D0%B4%D0%B5%D0%BB%D0%B5%D0%BD%D0%BD%D0%BE%D0%B3%D0%BE-%D0%B7%D0%BD%D0%B0%D0%BA%D0%B0

//  Алгоритм Spigot. Вывод пи с точностью, указываемой в командной строке:
//
//  clang++ -std=c++17 

using namespace std;

string Pi(int N)
{
    int M = (N*10+2)/3;
    vector<int> r(M,2);
    string pi;
    pi.reserve(N+1);
    for(int i = 0; i < N; ++i)
    {
        int carry = 0;
        int sum = 0;
        for(int j = M-1; j >= 0; --j)
        {
            r[j] *= 10;
            sum = r[j] + carry;
            int q = sum / (2*j+1);
            r[j]  = sum % (2*j+1);
            carry = q * j;
        }
        r[0] = sum % 10;
        int q = sum / 10;
        if (q >= 10)
        {
            q = q - 10;
            for(int j = pi.length()-1;;--j)
            {
                if (pi[j] == '9')
                    pi[j] = '0';
                else
                {
                    ++pi[j];
                    break;
                }
            }
        }
        pi += ('0' + q);
        if (i== 0) pi += '.';
    }
    return pi;
}

int main(int argc, const char * argv[])
{
    cout << Pi((argc == 1) ? 10 : atoi(argv[1])) << endl;
}

