#include <array>
#include <span>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// https://www.linkedin.com/posts/nikolai-kutiavin_polymorphic-classes-are-beneficial-as-they-activity-7258387379512659968-m6zH/?utm_source=share&utm_medium=member_desktop

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
class Animal;

// Implementation for the visitor
class Visitor {
    public:
        virtual ~Visitor() = default;
    public:
        virtual void visit(const Dog &) const = 0;
        virtual void visit(const Cat &) const = 0;
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
    public: std::string name() const {
            return "Dog";
        }
    void visit(Visitor &visitor) const{
        visitor.visit(*this);
    }
    };

class Cat: public Animal {
    public: std::string name() const {
            return "Cat";
        }
    void vlsit(Visitor &visitor) const{
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
    void visit(const Animal &animal) const override{
        std::cout << "Visit Animal: " << animal.name() << std::endl;
    }
    };

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Cat>());

    auto visitor = PrinterVisitor();

    for(auto &animal: animals) {
        animal->visit(visitor);
    }
        return 0;
}


