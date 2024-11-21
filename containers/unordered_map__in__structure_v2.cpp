#include <iostream>
#include <map>
#include <unordered_map>

// https://t.me/easy_c_plus/225
/*

Что нужно сделать, что бы хранить свою структуру в unordered_map?

 Чтобы хранить свою структуру в unordered_map, необходимо выполнить несколько шагов. Важно понимать, что unordered_map использует хеширование для быстрого доступа к элементам, поэтому для пользовательских структур требуется определить функции, которые будут использоваться для хеширования и сравнения ключей. Рассмотрим это подробно:

 ➕ Удобство: Возможность использовать пользовательские структуры в качестве ключей позволяет решать более сложные задачи и хранить данные в удобном для доступа формате.

 🤔 Как это используется?

 Для использования пользовательской структуры в unordered_map, необходимо:

 ➕ Определить функцию хеширования для структуры.

 ➕ Определить оператор сравнения для структуры.
 
   */

// Определение структуры
struct Point {
    int x, y;

    // Оператор сравнения
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Определение хеш-функции
struct PointHash {
    std::size_t operator()(const Point& p) const {
        // Простой пример хеш-функции
        return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
    }
};

int main() {
    // Создание unordered_map с пользовательской структурой в качестве ключа
    std::unordered_map<Point, std::string, PointHash> umap;

    // Добавление элементов
    umap[{1, 2}] = "Point A";
    umap[{3, 4}] = "Point B";

    // Доступ к элементам
    std::cout << "Point (1, 2): " << umap[{1, 2}] << std::endl;
    std::cout << "Point (3, 4): " << umap[{3, 4}] << std::endl;

    return 0;
}
