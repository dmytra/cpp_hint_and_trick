#include <iostream>
#include <vector>

class MemoryPool {
public:
    MemoryPool(size_t size) {
        pool.resize(size);
    }

    void* allocate(size_t size) {
        if (currentOffset + size > pool.size()) {
            throw std::bad_alloc();
        }
        void* ptr = pool.data() + currentOffset;
        currentOffset += size;
        return ptr;
    }

    void deallocateAll() {
        currentOffset = 0;
    }

private:
    std::vector<char> pool;
    size_t currentOffset = 0;
};

int main() {
    MemoryPool pool(1024); // Пул памяти размером 1024 байта

    int* p1 = static_cast<int*>(pool.allocate(sizeof(int)));
    *p1 = 42;

    double* p2 = static_cast<double*>(pool.allocate(sizeof(double)));
    *p2 = 3.14;

    std::cout << "p1: " << *p1 << ", p2: " << *p2 << std::endl;

    pool.deallocateAll(); // Освобождение всех выделенных блоков

    return 0;
}

/*
  Что знаешь про фрагментацию кучи?

Это явление, при котором память, выделенная в куче, разбивается на мелкие фрагменты, что может затруднить эффективное использование памяти и привести к снижению производительности. Фрагментация кучи бывает двух типов: внутренняя и внешняя.
 */
// https://t.me/easy_c_plus/541
