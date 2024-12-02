#include <iostream>
#include <vector>

// Какие есть сортировки ?
// https://t.me/easy_c_plus/142
// algorithmsort_Selection_Sort.cpp
/*
 Сортировка выбором (Selection Sort)
 ✅Принцип: Находит минимальный элемент из несортированной части массива и меняет его местами с первым элементом этой части.
 ✅Сложность: O(n^2) в худшем и среднем случаях.
 ✅Применение: Используется в случаях, когда количество перестановок имеет значение.
*/

         void selectionSort(std::vector<int>& arr) {
          for (size_t i = 0; i < arr.size() - 1; ++i) {
              size_t minIndex = i;
              for (size_t j = i + 1; j < arr.size(); ++j) {
                  if (arr[j] < arr[minIndex]) {
                      minIndex = j;
                  }
              }
              std::swap(arr[i], arr[minIndex]);
          }
      }

int main() {
    std::vector<int> arr = {1,32,3,444,5,3,54,4,54,5,34};
 
    for (auto it : arr) {
        std::cout << it << " ";
    }
    selectionSort(arr); std::cout <<  " \n";
    for (auto it : arr) {
        std::cout << it << " ";
    }
    
    return 0;
}

