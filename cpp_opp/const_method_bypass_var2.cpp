  #include <iostream>
// обойти константный метод?
//Приведение типа (const_cast)
// https://t.me/easy_c_plus/702
// const_method_bypass_var1.cpp
   
class MyClass {
public:
    MyClass(int v) : value(v) {}

    int getValue() const {
        return value;
    }

    void setValue(int newValue) const {
        const_cast<MyClass*>(this)->value = newValue; // Снятие константности
    }

private:
    int value;
};

int main() {
    const MyClass obj(10);
    std::cout << "Initial value: " << obj.getValue() << std::endl;
    obj.setValue(20); // Изменение константного объекта
    std::cout << "Modified value: " << obj.getValue() << std::endl;
    return 0;
}


