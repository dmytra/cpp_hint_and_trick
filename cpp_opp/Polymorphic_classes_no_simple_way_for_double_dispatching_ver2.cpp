#include <array>
#include <span>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

//clang++ -std=c++17 *.cpp

// https://www.linkedin.com/posts/nikolai-kutiavin_polymorphic-classes-are-beneficial-as-they-activity-7258387379512659968-m6zH/?utm_source=share&utm_medium=member_desktop
/*
 Polymorphic classes are beneficial as they help provide an abstract interface for a group of objects, allowing users to avoid worrying about the specific implementation. However, sometimes it can be crucial to perform actions based on the concrete type of the polymorphic class. Certainly, 𝚍𝚢𝚗𝚊𝚖𝚒𝚌_𝚌𝚊𝚜𝚝 can be used to perform conversions along the inheritance hierarchy, but there is another method: double dispatching.

 Double dispatching allows for executing different methods depending on the dynamic type of the argument. It requires two hierarchies to be linked: one for the classes themselves and another for the visitors. In the example below, I have an interface 𝙰𝚗𝚒𝚖𝚊𝚕 that provides a virtual method 𝚟𝚒𝚜𝚒𝚝(𝚅𝚒𝚜𝚒𝚝𝚘𝚛& 𝚟𝚒𝚜𝚒𝚝𝚘𝚛) 𝚌𝚘𝚗𝚜𝚝. Each child class should implement that method and call 𝚟𝚒𝚜𝚒𝚝𝚘𝚛.𝚟𝚒𝚜𝚒𝚝(*𝚝𝚑𝚒𝚜);, allowing the 𝚅𝚒𝚜𝚒𝚝𝚘𝚛 to determine the real type of the object and select the appropriate method. The visitor hierarchy defines a 𝚟𝚒𝚜𝚒𝚝 method for each child class from 𝙰𝚗𝚒𝚖𝚊𝚕.

 This method has a notable disadvantage—it tightly couples the 𝚅𝚒𝚜𝚒𝚝𝚘𝚛 interface to the hierarchy of 𝙰𝚗𝚒𝚖𝚊𝚕 classes, meaning that adding a new child class requires updating the 𝚅𝚒𝚜𝚒𝚝𝚘𝚛 interface.
 */

// Interface that provides a general double dispatching capabilities
template<typename T>
class Visitable {
    public:
        virtual ~Visitable() = default;
    public:
        virtual void visit( T &visitor) const = 0;
};

class Dog;
class Cat;
class DogRex;
class Animal;

// Implementation for the visitor
class Visitor {
    public:
        virtual ~Visitor() = default;
    public:
        virtual void visit(const Dog &) const = 0;
        virtual void visit(const Cat &) const = 0;
        virtual void visit(const DogRex &) const = 0;
        virtual void visit(const Animal &) const = 0;
};

// Base class for the animals.
// Define base-functionality and inherits visitor
class Animal : public Visitable<Visitor> {
    public:
        virtual ~Animal() = default;
    public:
        virtual std::string name() const = 0;
};

class Dog : public Animal {
    public:
        std::string name() const {
            return "Dog";
        }
        void visit(Visitor &visitor) const{
            visitor.visit(*this);
        }
};

class Cat : public Animal {
    public:
        std::string name() const {
            return "Cat";
        }
        void visit(Visitor &visitor) const{
            visitor.visit(*this);
        }
};

class DogRex : public Animal {
    public:
        std::string name() const {
            return "DogRex";
        }
        void visit(Visitor &visitor) const{
            visitor.visit(*this);
        }
};
    
class PrinterVisitor : public Visitor {
    public:
    void visit(const Dog &dog) const override {
        std::cout << "Visit Dog: " << dog.name() << std::endl;
    }
    void visit(const Cat &cat) const override{
        std::cout << "Visit Cat: " << cat.name() << std::endl;
    }
    void visit(const DogRex &dogrex) const override {
        std::cout << "Visit DogRex: " << dogrex.name() << std::endl;
    }
    void visit(const Animal &animal) const override{
        std::cout << "Visit Animal: " << animal.name() << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<DogRex>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Cat>());
    
    auto visitor = PrinterVisitor();

    for(auto &animal: animals) {
        animal->visit(visitor);
    }
    return 0;
}
