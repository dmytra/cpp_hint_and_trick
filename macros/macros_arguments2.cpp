#define SQUARE(x) ((x) * (x))

int main() {
    int a = 5;
    int b = 3;
    int result = SQUARE(a + b); // Теперь результат будет корректным: ((5 + 3) * (5 + 3)) = 64
    std::cout << result << std::endl; // Результат будет 64
    return 0;
}
// Почему аргументы в макросах нужно брать в скобки? 
// https://t.me/easy_c_plus/589
