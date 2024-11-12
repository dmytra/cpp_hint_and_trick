 
 #include <iostream>
  

 int main()
 {
 auto start_time = std::chrono::high_resolution_clock::now();
 std::uint64_t count = 0;

     for(int i = 0; i <= 10; i++)
     {
         uint64_t aaa = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()-start_time).count();
         std::cout << aaa << "\n";
     }

 }
//https://en.cppreference.com/w/cpp/chrono/duration
// std::chrono::nanoseconds    std::chrono::duration</* int64 */, std::nano>
// std::chrono::microseconds    std::chrono::duration</* int55 */, std::micro>
// std::chrono::milliseconds    std::chrono::duration</* int45 */, std::milli>
// std::chrono::seconds    std::chrono::duration</* int35 */>
// std::chrono::minutes    std::chrono::duration</* int29 */, std::ratio<60>>
// std::chrono::hours    std::chrono::duration</* int23 */, std::ratio<3600>>
// std::chrono::days (since C++20)    std::chrono::duration</* int25 */, std::ratio<86400>>
// std::chrono::weeks (since C++20)    std::chrono::duration</* int22 */, std::ratio<604800>>
// std::chrono::months (since C++20)    std::chrono::duration</* int20 */, std::ratio<2629746>>
// std::chrono::years (since C++20)    std::chrono::duration</* int17 */, std::ratio<31556952>>
 
