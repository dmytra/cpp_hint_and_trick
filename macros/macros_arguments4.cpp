#define INCREMENT(x) ((x) + 1)

int main() {
    int a = 5;
    int result = INCREMENT(a++); // Теперь результат будет корректным: ((5) + 1) = 6
    std::cout << result << std::endl; // Результат будет 6, и a станет 6
    return 0;
}
// Почему аргументы в макросах нужно брать в скобки? 
// https://t.me/easy_c_plus/589
