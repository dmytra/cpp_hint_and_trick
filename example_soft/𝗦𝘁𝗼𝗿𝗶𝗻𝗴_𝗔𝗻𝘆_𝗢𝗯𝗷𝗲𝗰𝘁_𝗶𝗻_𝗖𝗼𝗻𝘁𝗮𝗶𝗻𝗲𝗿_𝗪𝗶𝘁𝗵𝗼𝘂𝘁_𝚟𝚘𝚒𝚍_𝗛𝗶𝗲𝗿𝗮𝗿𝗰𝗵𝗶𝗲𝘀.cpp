#include <iostream>
#include <unordered_map>
#include <any>
#include <typeindex>
#include <memory>
#include <stdexcept>
#include <mutex>

// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-stdany-typeerasure-activity-7263636520442515456-oDkT/?utm_source=share&utm_medium=member_desktop
// https://lnkd.in/eqGePtTX

class SingletonStorage {
public:
    // Template method to get or create an instance of the specified type
    template <typename T>
    T& get() {
        std::type_index typeIndex(typeid(T));

        // Check if the object already exists
        auto it = storage.find(typeIndex);
        if (it != storage.end()) {
            // Retrieve and cast the stored object
            return std::any_cast<T&>(it->second);
        }

        // Create a new instance if not found
        // noexcept move constructor will be used, but type should be copieable
        auto insert = storage.emplace(typeIndex, std::make_any<T>());

        // Return a reference
        return std::any_cast<T&>(insert.first->second);
    }

    // Delete copy and assignment operators to ensure singleton behavior
    SingletonStorage(const SingletonStorage&) = delete;
    SingletonStorage& operator=(const SingletonStorage&) = delete;

    static SingletonStorage& instance() {
        static SingletonStorage instance;
        return instance;
    }

private:
    SingletonStorage() = default;

    std::unordered_map<std::type_index, std::any> storage;  // Map of type-indexed singletons
};

// Example classes to be managed by SingletonStorage
class MyClass1 {
public:
    void display() const {
        std::cout << "MyClass1 instance\n";
    }
};

class MyClass2 {
public:
    void show() const {
        std::cout << "MyClass2 instance\n";
    }
};

int main() {
    // Retrieve and use instances of MyClass1 and MyClass2 from SingletonStorage
    auto& obj1 = SingletonStorage::instance().get<MyClass1>();
    auto& obj2 = SingletonStorage::instance().get<MyClass2>();

    obj1.display();  // Output: MyClass1 instance
    obj2.show();     // Output: MyClass2 instance

    // Retrieve the same instances again to verify singleton behavior
    auto& sameObj1 = SingletonStorage::instance().get<MyClass1>();
    auto& sameObj2 = SingletonStorage::instance().get<MyClass2>();

    // The same instances are used, so no new output
    sameObj1.display();  // Output: MyClass1 instance
    sameObj2.show();     // Output: MyClass2 instance

    return 0;
}

