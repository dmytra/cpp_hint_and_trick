// https://www.linkedin.com/posts/nikolai-kutiavin_cpp20-stdatomic-consumerproducer-activity-7255473302662475776-JiZ6/?utm_source=share&utm_medium=member_desktop

/*
𝚜𝚝𝚍::𝚊𝚝𝚘𝚖𝚒𝚌::𝚠𝚊𝚒𝚝 allows the calling thread to block while waiting for updates to the value of a 𝚜𝚝𝚍::𝚊𝚝𝚘𝚖𝚒𝚌.
 Building a consumer-producer pattern with two atomics? That's easy with
 this feature. Since there's no queue, the consumer should not only take
 a value from the producer but also notify when values are consumed to 
prevent skipping produced values. The example below demonstrates that 
implementation:
*/
#include <iostream>
#include <atomic>
#include <thread>

#include <atomic>
#include <type_traits>
#include <cstring>

int main() { 
	// Need to notify consumer about new value produced 
	std::atomic<int> produced{-1}; 
	// Needed to notify producer that value was handled 
	std::atomic<int> consumed{-1}; 

	auto consumer = std::jthread([&produced, &consumed]{ 
		for(int value = -1; value < 99;) { 
		
		// Wait until value update 
		produced.wait(value); 
		
		// Save updated value locally for further waiting operation 
		value = produced; 
		
		// Do some useful job with obtained 'value' 
		std::osyncstream(std::cout) << "consumed: " << value << std::endl; 

		// Notify producer that 'value' is handled and thread is 
		// ready for the next one 
		consumed = value; 
		consumed.notify_one(); 
		}
	}); 

	// Last consumed value 
	int consumedValue = -1; 
	for(int i = 0; i <= 99; ++i) { 
		// Generate a value 
		std::osyncstream(std::cout) << "produced: " << i << std::endl; 
		
		// Set new value and notify consumer about update 
		produced = i; 
		produced.notify_one(); 

		// Block and wait until consumers report 
		consumed.wait(consumedValue); 
		consumedValue = consumed; 
	}
	
	return 0;
}


