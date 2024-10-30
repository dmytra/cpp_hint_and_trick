//
//  C_object-oriented.c
//  test1
//
//  Created by Dmytra on 30.10.2024.
//  Copyright © 2024 Dmytra. All rights reserved.
//

// https://www.linkedin.com/posts/nikolai-kutiavin_cprogramming-objectorientedprogramming-oopinc-activity-7257300321427689472-DYgO?utm_source=share&utm_medium=member_desktop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Base class: Animal
typedef struct {
    char name[20];
    void (*speak)(struct Animal*); // Function pointer for polymorphism
} Animal ;

// Function to set the name of the animal (encapsulation)
void set_name(Animal* animal, const char* name) {
strncpy(animal->name, name, sizeof(animal->name) - 1);
animal->name[sizeof(animal->name) - 1] ='\0'; // Ensure null-termination
}

// Derived class: Dog (inherits from Animal)
typedef struct {
    Animal base; // Composition to simulate inheritance
} Dog;

// Function to simulate the "speak" behavior of a dog
void dog_speak(Animal* animal) {
    printf("%s says: Woofl\n", animal->name);
}

// Function to create a Dog object
Dog* create_dog(const char* name) {
    Dog* dog = (Dog*)malloc(sizeof(Dog));
    set_name((Animal*)dog, name); // Set the dog's name
    dog->base.speak = dog_speak; // Assign dog-specific speak function
    return dog;
}

// Derived class: Cat (inherits from Animal)
typedef struct {
    Animal base; // Composition to simulate inheritance
} Cat;

// Function to simulate the "speak" behavior of a cat
void cat_speak(Animal* animal) {
    printf("%s says: Memd\n", animal->name);
}

// Function to create a Cat object
    Cat* create_cat(const char* name) {
          Cat* cat = (Cat*)malloc(sizeof(Cat));
    set_name((Animal*)cat, name); // Set the cat's name
    cat->base.speak = cat_speak; // Assign cat-specific speak function
    return cat;
}

int main() {
    // Create instances of Dog and Cat
    Dog* myDog = create_dog("Buddy");
    Cat* myCat = create_cat("Whiskers");

    // Polymorphic behavior
    Animal* animals[] = {(Animal*)myDog, (Animal*)myCat};

    // Call the "speak" method for each animal
    for (int i = 0; i < 2; i++) {
        animals[i]->speak(animals[i]);
    }

    // Clean up
    free(myDog);
    free(myCat);

    return 0;
}

