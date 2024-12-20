// Проверка равенства двух чисел с плавающей точкой (float или double) в C++
// https://t.me/easy_c_plus/111

/*
 Основные принципы проверки равенства

 1️⃣Использование эпсилон-значения:
 ✅Эпсилон-значение (epsilon) представляет собой небольшую величину, которая определяет допустимую разницу между двумя числами с плавающей точкой. Два числа считаются равными, если их абсолютная разница меньше эпсилон-значения.

 2️⃣Абсолютная и относительная разница:
 ✅Абсолютная разница может быть достаточной для чисел вблизи нуля.
 ✅Относительная разница лучше подходит для чисел, которые могут быть как большими, так и малыми.
 */

#include <cmath>
#include <iostream>

// Функция для проверки равенства двух чисел с плавающей точкой
bool almostEqual(float a, float b, float epsilon = 1e-5f) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    float x = 0.1f * 7.0f; // x должно быть примерно равно 0.7
    float y = 0.7f;

    if (almostEqual(x, y)) {
        std::cout << "x и y примерно равны." << std::endl;
    } else {
        std::cout << "x и y не равны." << std::endl;
    }

    return 0;
}


