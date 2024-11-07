#include <iostream>
#include <string>

// https://www.linkedin.com/posts/mariusz-hoepfner_cpp-cppprogramming-softwaredesign-activity-7259920134541066241-_ia8/?utm_source=share&utm_medium=member_desktop

// Without YAGNI.
// YAGNI is very important. Never develop something not useful from the start

class UserWithoutYagni {
public:
    std::string username;
    std::string address; // Not needed yet, but might be useful later
    int age; // Not needed yet, but might be useful later
    
    UserWithoutYagni(std::string username) : username(username), address(""), age(0) {}

    void set_address(const std::string& addr) {
        address = addr;
}
    void set_age(int a) {
        age = a;
    }
};

    
// With YAGNI
    class UserWithYagni {
    public:
        std::string username;

        UserWithYagni(std::string username) : username(username) {}
};

int main() {
        // Create an instance without YAGNI
    UserWithoutYagni u1("John_doe");
        std::cout << "User (without YAGNI): Username: " << u1.username <<std::endl;
// Create an instance with YAGNI
        UserWithYagni u2 ("jane_smith");
        std::cout << "User (with YAGNI): Username: " << u2.username << std::endl;

        return 0;
}

