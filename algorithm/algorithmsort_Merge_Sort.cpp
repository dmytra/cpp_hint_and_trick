#include <iostream>
#include <vector>

// Какие есть сортировки ?
// https://t.me/easy_c_plus/142
// algorithmsort_Merge_Sort.cpp
/*
 Сортировка слиянием (Merge Sort)
 ✅Принцип: Делит массив на две половины, рекурсивно сортирует каждую половину и сливает их обратно.
 ✅Сложность: O(n log n) в худшем, среднем и лучшем случаях.
 ✅Применение: Эффективен для больших массивов, стабилен и может быть реализован для сортировки на внешней памяти.
*/

            void merge(std::vector<int>& arr, int left, int mid, int right) {
             std::vector<int> temp(right - left + 1);
             int i = left, j = mid + 1, k = 0;
             while (i <= mid && j <= right) {
                 if (arr[i] <= arr[j]) {
                     temp[k++] = arr[i++];
                 } else {
                     temp[k++] = arr[j++];
                 }
             }
             while (i <= mid) {
                 temp[k++] = arr[i++];
             }
             while (j <= right) {
                 temp[k++] = arr[j++];
             }
             for (int i = left, k = 0; i <= right; ++i, ++k) {
                 arr[i] = temp[k];
             }
         }

         void mergeSort(std::vector<int>& arr, int left, int right) {
             if (left < right) {
                 int mid = left + (right - left) / 2;
                 mergeSort(arr, left, mid);
                 mergeSort(arr, mid + 1, right);
                 merge(arr, left, mid, right);
             }
         }

int main() {
    std::vector<int> arr = {1,32,3,444,5,3,54,4,54,5,34};
 
    for (auto it : arr) {
        std::cout << it << " ";
    }
    mergeSort(arr,1,3); std::cout <<  " \n";
    for (auto it : arr) {
        std::cout << it << " ";
    }
    
    return 0;
}

