
// https://www.linkedin.com/posts/nikolai-kutiavin_linux-sharedlibraries-dynamicloading-activity-7260199395055357960-uwJQ/?utm_source=share&utm_medium=member_desktop
//

#include <iostream> 
#include <dlfcn.h> 

typedef void (*hello_func)(); 

int main() { 
	// Load the shared library 
	auto handle = 
		std::unique ptr<void *, dlclose>(dlopen("./libexample.so", RTLD_LAZY)); 
	if (!handle) { 
		std::cerr << "Error loading library: " << dlerror() << std::endl; 
	return 1; 
	}

	// Clear any existing errors 
	dlerror(); 
	
	// Get a pointer to the 'hello' function 

	hello_func hello = static_cast<hello_func>(dlsym(handle.get(), "hello")); 
	const char* dlsym_error = dlerror(); 
	if (dlsym_error) { 
		std::cerr << "Error loading symbol 'hello': " << dlsym_error << std::end;
		return 1; 
	}

	// Call the 'hello' function 
	hello(); 
	
	return 0; 
}


