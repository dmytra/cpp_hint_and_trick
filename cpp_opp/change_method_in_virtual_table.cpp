//I am able to change a method in a virtual table in C++?
// https://www.linkedin.com/posts/vchizh_cpp-cplusplus-programming-activity-7272705535366361089-456a/?utm_source=share&utm_medium=member_desktop

#include <iostream>
#include <cstdint>
#include <sys/mman.h>
#include <unistd.h>
#include <memory>

class Base {
public:
    virtual void display() {
        std::cout << "Display from Base class\n";
    }
    virtual ~Base() = default;
};

    void HackTheSystem(void* obj) {
        std::cout << "Hack The System!\n";
    }
int main() {
    std::unique_ptr<Base> basePtr(new Base());
    basePtr->display();
    void** vtable = *(void***)basePtr.get();
    uintptr_t pageStart = reinterpret_cast<uintptr_t>(vtable) & ~(getpagesize() - 1);
    if (mprotect(reinterpret_cast<void*>(pageStart), getpagesize(), PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        perror("mprotect");
        return 1;
    }
    
    void* originalFunction = vtable[0];
    vtable[0] = reinterpret_cast<void*>(&HackTheSystem);
    basePtr->display();
    vtable[0] = originalFunction;
    basePtr->display();
    if (mprotect(reinterpret_cast<void*>(pageStart), getpagesize(), PROT_READ | PROT_EXEC) != 0) {
        perror("mprotect");
        return 1;
    }
    return 0;
}


