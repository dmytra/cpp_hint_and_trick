#include <iostream>
#include <thread>
#include <array>
#include <latch>
#include <semaphore>

// only c++ 20

// c++ -std=c++2a file_name.cpp

// https://www.linkedin.com/posts/samira-mh_cpp20-cpp-semaphores-activity-7248154153145827329-vpT_/?utm_source=share&utm_medium=member_desktop

// Struct to hold shared resources between threads
struct SharedResource
{
    static constexpr int BUFFER_SIZE {10};

    // Shared buffer
    std::array<int, BUFFER_SIZE> data{};

    // Semaphores to control the execution flow between producer and consumer
    std::binary_semaphore producer{1};     // Indicating that the producer initially can produce a value
    std::binary_semaphore consumer{0};     // Indicating that the consumer initially cannot consume a value

    // Latch to ensure main waits for both threads (producer and consumer)
    // to complete before proceeding
    std::latch done{2};
};

// Function executed by the consumer thread
void consumeData(SharedResource& resource)
{
    for (int i = 0; i < SharedResource::BUFFER_SIZE; ++i)
    {
        // Wait for the producer to signal that data is ready
        resource.consumer.acquire();

        std::cout << "Consumer Reads:  " << resource.data[i] << '\n';

        // Simulate some processing time
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

        // Signal the producer to continue production
        resource.producer.release();
    }
    // Signal completion of the consumer thread to the latch
    resource.done.count_down();
}

// Function executed by the producer thread
void produceData(SharedResource& resource)
{
    for (int i = 0; i < SharedResource::BUFFER_SIZE; ++i)
    {
        // Wait for the consumer to signal readiness
        resource.producer.acquire();

        resource.data[i] = i;

        std::cout << "Producer writes: " << resource.data[i] << '\n';

        // Simulate some processing time
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        // Signal the consumer that data is ready
        resource.consumer.release();
    }
    // Signal completion of the producer thread to the latch
    resource.done.count_down();
}

int main()
{
    SharedResource resource;
    std::jthread producer(produceData, std::ref(resource));
    std::jthread consumer(consumeData, std::ref(resource));

    // Main thread waits here until both threads signal completion via the latch
    resource.done.wait();

    // Output the data processed by threads
    for (int value : resource.data)
    {
        std::cout << value << " ";
    }
    return 0;
}

