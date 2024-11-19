class Base {
public:
    virtual void display() const {
        std::cout << "Base display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {  // Ошибка компиляции: функция не совпадает по сигнатуре
        std::cout << "Derived display" << std::endl;
    }
};
//  Что значит ключевое слово override? 
// https://t.me/easy_c_plus/551