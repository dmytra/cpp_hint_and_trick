#include <iostream>
#include <vector>

// https://t.me/easy_c_plus/640

int main() {
    std::vector<int> vec;
    int previous_capacity = vec.capacity();

    for (int i = 0; i < 20; ++i) {
        vec.push_back(i);
        if (vec.capacity() != previous_capacity) {
            std::cout << "Capacity changed: " << previous_capacity << " -> " << vec.capacity() << std::endl;
            previous_capacity = vec.capacity();
        }
    }

    return 0;
}

