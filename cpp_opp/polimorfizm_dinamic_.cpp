 #include <iostream>
 // Что такое полиморфизм?
 // Одно из фундаментальных понятий объектно-ориентированного программирования (ООП), которое позволяет объектам разных классов быть обработанными единообразно
 // polimorfizm_dinamic_.cpp

 // https://t.me/easy_c_plus/674
 // Полиморфизм времени выполнения (динамический полиморфизм)

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Cat meows" << std::endl;
    }
};

void makeAnimalSpeak(const Animal& animal) {
    animal.speak(); // Вызов виртуальной функции
}

int main() {
    Dog dog;
    Cat cat;
    makeAnimalSpeak(dog); // Выведет: Dog barks
    makeAnimalSpeak(cat); // Выведет: Cat meows

    return 0;
}

 

