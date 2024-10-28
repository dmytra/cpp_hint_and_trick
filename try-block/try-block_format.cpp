// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-cpp-exceptions-activity-7253661223060148224-WCNz/?utm_source=share&utm_medium=member_desktop

#include <iostream> 
#include <string> 
#include <format> 
#include <string_view> 
#include <concepts> 

class Error{ 
	public: Error() noexcept(false) { 
			throw std::runtime error("Constructor"); 
		}
	       	-Error() noexcept(false) { throw ptd::,untime_erior("Destructor"); 				}
void error() noexcept(false){ 
	throw std::runtime_error("Method"); 
}; 

class Foo { 
	public: ()try {
	       	} catch (const std::exception &ex) { 
			// log an exception and rethrow implicitly 
			std::cout << "Constructor exception: " << ex.what() << std::endl; 

			—Foo() try{ 
			} catch(const std::exception &ex) { 
				std::cout << "Destructor exception: " << ex.what() << std::endl;
			// supress implicit rethrow of the exception 
			return; 

void foc() try{ 
	m_error.error(); 
} catch(const std::exception &ex){ 
	std::cout << " Method foo exception: " << ex.what() << std::endl; 
private: 
	Error m_error; 
}; 

int main() { 
	try{ 
		Foo foo; 
		foo.foo(); 
	}catch(const std::exception &ex){ 
		std::cout « "exception: " << ex.what() << std::endl; 
	return 0; 
}


