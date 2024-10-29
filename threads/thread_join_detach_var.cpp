#include <iostream> 
#include <thread> 
#include <chrono> 

void fun1(){ 
	for(int i=0 ;i<15; i++){ 

	std::this_thread::sleep_for(
			std::chrono::milliseconds(1000)); 
	std::cout << "in fun1. count: " << i + 1 << std::endl; 
	}
}	

void fun2(){ 
	for(int i=0 ;i<15; i++){ 

	std::this_thread::sleep_for(
			std::chrono::milliseconds(500)); 
	std::cout << "in fun2. count: " << i + 1 << std::endl; 
	}
}


//
void fun11(){ 
	for(int i=0 ;i<5; i++){ 

	std::this_thread::sleep_for(
			std::chrono::milliseconds(1000)); 
	std::cout << "=====in fun11. count: " << i + 1 << std::endl; 
	}
}	

void fun12(){ 
	for(int i=0 ;i<5; i++){ 

	std::this_thread::sleep_for(
			std::chrono::milliseconds(500)); 
	std::cout << "|||||||in fun12. count: " << i + 1 << std::endl; 
	}
}


//
int main(){ 
	std::thread t1(&fun1); 
	std::thread t2(&fun2); 

	std::cout << "WITHOUT COUNT in fun1 & fun2 ! "<< std::endl; 
	t1.detach(); 
	t2.detach(); 

	int flag;
	std::cin >> flag;
	
if (flag != 1) {
	std::thread t11(&fun11); 
	std::thread t12(&fun12); 
	
	std::cout << "in fun1. count: "  << std::endl; 
	t11.detach(); 
	t12.join(); 
}

	return 0;
}	
//https://www.linkedin.com/posts/naser-rezayi-89774723b_cpp-cplusplus-concurrency-activity-7249726367469060097-TAGq/?utm_source=share&utm_medium=member_desktop
//

/*
join() synchronizes with the thread, while detach() runs the thread independently.

join() ensures the main thread waits for the completion, but detach() does not.

Once a thread is detached, you can no longer interact with it, whereas a joined thread can be safely synchronized.

*/
