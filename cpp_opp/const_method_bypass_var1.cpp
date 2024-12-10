  #include <iostream>
// обойти константный метод?
// Использование ключевого слова `mutable`
// https://t.me/easy_c_plus/702
// const_method_bypass_var1.cpp
   
class MyClass {
public:
    MyClass(int v) : value(v) {}

    int getValue() const {
        ++accessCount; // Допустимо, так как accessCount объявлен как mutable
        return value;
    }

private:
    int value;
    mutable int accessCount = 0; // mutable позволяет изменять переменную в const методах
};

int main() {
    MyClass obj(10);
    obj.getValue(); // accessCount будет увеличен
    return 0;
}

