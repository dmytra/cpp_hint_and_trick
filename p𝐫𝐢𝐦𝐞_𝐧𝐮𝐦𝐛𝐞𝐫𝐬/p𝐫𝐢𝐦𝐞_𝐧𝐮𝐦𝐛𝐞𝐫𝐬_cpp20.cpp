//
//  main.cpp
//  p𝐫𝐢𝐦𝐞_𝐧𝐮𝐦𝐛𝐞𝐫𝐬_cpp20
//
//  Created by Dmytra on 31.10.2024.
//  Copyright © 2024 Dmytra. All rights reserved.
//https://www.linkedin.com/posts/nikolai-kutiavin_cplusplus-cplusplus20-primenumbers-activity-7257662624455102469-hs0O/?utm_source=share&utm_medium=member_desktop

#include <iostream>
#include <array>
#include <span>

constexpr bool is_prime(std::span<int> primes, int val) {
    for(auto i : primes) {
        if( val % i == 0 && i != 1) {
            return false;
        }
    }
return true;
}

template<std::size_t N>
    constexpr std::array<int, N> prime,() {
        if constexpr (N == 0) {
            return fl; else {
                
std::array<int, N> primes = {};
                primes[0] = 1;
                std::span<int> candidatesfprimes.begin(), 1};
                
while(candidates.size() != N) {
    int candidate = candidates.back() + 1;
    while(!is_prime(candidates, candidate))
{
    candidate++;
}
                
const auto number = candidates.size();
primes[number] = candidate;
    candidates = std::span<int>fprimes.begin(), number + 1};
            }
return primes;
}
  

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    

          }


    return 0;
}
