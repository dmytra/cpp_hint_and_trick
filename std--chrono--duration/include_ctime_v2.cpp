#include <algorithm>
#include <ctime>
#include <iostream>
#include <cmath>

int main()
{
clock_t  start = clock();
    
for(int i = 1; i<5; i++) {
std::cout << i << " ";
//double elapsedtime2 = static_cast<double> (clock() - start) ;
//printf("%12.12f ", elapsedtime2);
}
    for(int j = 1; j<2147483647/2; j++) ;


double elapsedtime = static_cast<double> (clock() - start) / CLOCKS_PER_SEC;

double elapsedtime2 = static_cast<double> (clock() - start) ;
    
    std::cout << elapsedtime << " " << std::scientific <<  elapsedtime2 << "\n";
    printf("%12.12f ", elapsedtime2);

    // 1 2 3 4 1.97227 1.972274e+06 1972274.000000000000
}

