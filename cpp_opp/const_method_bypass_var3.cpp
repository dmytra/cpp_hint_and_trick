  #include <iostream>
// обойти константный метод?
//Использование шаблонов и специализированных методов
// https://t.me/easy_c_plus/702
// const_method_bypass_var1.cpp
   
class MyClass {
public:
    MyClass(int v) : value(v) {}

    template<typename T>
    int getValue(T* obj) const {
        if constexpr (std::is_const_v<T>) {
            return obj->value; // Просто возвращаем значение для константных объектов
        } else {
            return ++obj->value; // Изменяем значение для неконстантных объектов
        }
    }

private:
    mutable int value;
};

int main() {
    MyClass obj(10);
    const MyClass constObj(20);

    std::cout << "Non-const object value: " << obj.getValue(&obj) << std::endl; // Увеличивает значение
    std::cout << "Const object value: " << constObj.getValue(&constObj) << std::endl; // Просто возвращает значение
    return 0;
}



