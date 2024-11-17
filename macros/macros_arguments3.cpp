#define INCREMENT(x) x + 1

int main() {
    int a = 5;
    int result = INCREMENT(a++); // Ожидается (5 + 1) = 6, но результат будет неверный
    std::cout << result << std::endl; // Результат будет 5 + 1, а a станет 7
    return 0;
}
// Почему аргументы в макросах нужно брать в скобки? 
// https://t.me/easy_c_plus/589
