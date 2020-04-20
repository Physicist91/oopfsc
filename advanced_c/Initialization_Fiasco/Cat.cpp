#include "Cat.h"
#include "Dog.h"
#include "Global.h"
#include <iostream>

//extern Dog d;
//Cat c("Smokey");

void Cat::meow() {
   std::cout << "Cat rules! My name is "  << name << std::endl;
}

Cat::Cat(char* n) {
   std::cout << "Constructing Cat" << std::endl;
   name = n;
   //d.bark();
   Global::getDog()->bark();
}

