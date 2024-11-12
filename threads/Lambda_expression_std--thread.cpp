#include <iostream>
#include <thread>
// https://riptutorial.com/cplusplus/example/2330/creating-a-std--thread
 
int main()
{
    auto lambda = [](int a) { std::cout << a << '\n'; };

    // Create and execute the thread
    std::thread thread(lambda, 10); // Pass 10 to the lambda expression
 
    // The lambda expression will be executed in a separate thread
 
    // Wait for the thread to finish, this is a blocking operation
    thread.join();
 
    return 0;
}