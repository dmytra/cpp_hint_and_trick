#include <iostream> 
#include <thread> 
#include <chrono> 

void fun1(){ 
	for(int i=0 ;i<5; i++){ 

	std::this_thread::sleep_for(
			std::chrono::milliseconds(1000)); 
	std::cout << "in fun1. count: " << i + 1 << std::endl; 
	}
}	

void fun2(){ 
	for(int i=0; i<0; i++){ 
		std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
		
		std::cout << "in fun2. count: " << i + 1 << std::endl; 
	}
}	

int main(){ 
	std::thread t1(&fun1); 
	std::thread t2(&fun2); 
	t1.detach(); 
	t2.join(); 
	return 0;
}	
//https://www.linkedin.com/posts/naser-rezayi-89774723b_cpp-cplusplus-concurrency-activity-7249726367469060097-TAGq/?utm_source=share&utm_medium=member_desktop
//
/*
join() synchronizes with the thread, while detach() runs the thread independently.

join() ensures the main thread waits for the completion, but detach() does not.

Once a thread is detached, you can no longer interact with it, whereas a joined thread can be safely synchronized.

*/
