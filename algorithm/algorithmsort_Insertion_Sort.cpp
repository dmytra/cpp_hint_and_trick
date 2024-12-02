#include <iostream>
#include <vector>

// Какие есть сортировки ?
// https://t.me/easy_c_plus/142
// algorithmsort_Insertion_Sort.cpp
/*
 Сортировка вставками (Insertion Sort)
 ✅Принцип: Постепенно строит отсортированный подмассив, вставляя элементы в правильное место.
 ✅Сложность: O(n^2) в худшем и среднем случаях.
 ✅Применение: Эффективен для небольших массивов или почти отсортированных данных.
*/

      void insertionSort(std::vector<int>& arr) {
       for (size_t i = 1; i < arr.size(); ++i) {
           int key = arr[i];
           int j = i - 1;
           while (j >= 0 && arr[j] > key) {
               arr[j + 1] = arr[j];
               --j;
           }
           arr[j + 1] = key;
       }
   }
   

int main() {
    std::vector<int> arr = {1,32,3,444,5,3,54,4,54,5,34};
 
    for (auto it : arr) {
        std::cout << it << " ";
    }
    insertionSort(arr); std::cout <<  " \n";
    for (auto it : arr) {
        std::cout << it << " ";
    }
    
    return 0;
}

