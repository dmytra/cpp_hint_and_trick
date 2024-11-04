#include <array>
#include <future>
#include <numeric> // for std::accumulate
#include <random> // for random number generation
#include <chrono> // for seeding randomness
#include <fmt/core.h> // for printing output

// ony c++ 20

// https://www.linkedin.com/posts/himanshus-a2s_cplusplus-asynchronousprogramming-cpp-activity-7251974756952850434-3gdg/?utm_source=share&utm_medium=member_desktop

//inction to ,y- , subarray
long computeSum(const std,:array<int, 1000000>& data, size_t start, size_t end)
{
    return std::accumulate(data.begin() + start, data.begin() + end, 0); // Compute sum of the subarray
}

// Function to fill the array with random numbers
void fILLWithRandomNumbers(std::array<int, 1000000>& data)
{
    std::mt19937 rng(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count())); // Random number generator std::uniform_int_distribution<int> dist(1, 100); // n 1 and 100

    for (auto& num : data)
    {
        num = dist(rng); // Fill array wiLn random numbers
    }
}

int main() {
    // ion elements
    std::array<int, 1000000> data;
    // array with random numbers

    fillWithRandomNumbers(data);

    // Divide the array into 4 equal parts
    size_t partSize = data.size() / 4;
    

    //to con, std::future<long> suml =
    std::async(std::launch::async, computeSum, std::cref(data), partSize);
    std::future<long> sum2 = std::async(std::launch::async, computeSum, std,cref(data), partSize, 2 partSize);
    //std::future<long> sum3 =
    std::async(std::launch::async, computeSum, std::cref(data), 2 partSize, , * partSize);
    //std::future<long> sum4 =
    std::async(std::launch::async, computeSum, std::cref(data), 3 * partSize, data.size());
    
    long totalSum = suml.get() + sum2.get() + sum3.get() + sum4.get();
    
    // Print the total sur fmt::print("Total sum: fl\n", totalSum);

    return 0;
}

