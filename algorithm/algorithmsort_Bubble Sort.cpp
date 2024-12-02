#include <iostream>
#include <vector>

// Какие есть сортировки ?
// https://t.me/easy_c_plus/142
// algorithmsort_Bubble Sort.cpp
/*
 1️⃣Пузырьковая сортировка (Bubble Sort)
 ✅Принцип: Повторно проходит по списку, сравнивая соседние элементы и меняя их местами, если они находятся в неправильном порядке.
 ✅Сложность: O(n^2) в худшем и среднем случаях.
 ✅Применение: Образовательные цели, так как алгоритм прост для понимания, но неэффективен для больших данных.
*/

   void bubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> arr = {1,32,3,444,5,3,54,4,54,5,34};
 
    for (auto it : arr) {
        std::cout << it << " ";
    }
    bubbleSort(arr); std::cout <<  " \n";
    for (auto it : arr) {
        std::cout << it << " ";
    }
    
    return 0;
}

