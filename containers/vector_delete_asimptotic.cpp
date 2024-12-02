#include <iostream>
#include <vector>

/*
В чем сложность операции удаления элемента в vector ?
https://t.me/easy_c_plus/128
 
vector_delete_asimptotic.cpp

Удаление элемента из std::vector может быть сложной операцией из-за необходимости смещения последующих элементов, что приводит к временной сложности O(n). Это делает удаление элементов из середины вектора менее эффективным по сравнению с удалением элементов из начала или конца.
 
 
 */
int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.erase(vec.begin() + 2); // Удаление элемента "3"
    // Последующие элементы (4, 5) сдвигаются на одну позицию влево

    // Вывод элементов после удаления
    for (int num : vec) {
        std::cout << num << " ";
    }
    
    std::cout <<  " \n" << std::endl;
 
    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Удаление элемента из середины (индекс 5)
    vec1.erase(vec1.begin() + 5);

    // Вывод элементов после удаления
    for (int num : vec1) {
        std::cout << num << " ";
    }
    vec1.shrink_to_fit();
    
    std::cout <<  " \n" << std::endl;
    int value_to_remove = 5;
    vec1.erase(std::remove(vec1.begin(), vec1.end(), value_to_remove), vec1.end());
    
    value_to_remove = 1;
    vec1.erase(std::remove(vec1.begin(), vec1.end(), value_to_remove), vec1.end());
    
    for (int num : vec1) {
        std::cout << num << " ";
    }
    
    return 0;
}

