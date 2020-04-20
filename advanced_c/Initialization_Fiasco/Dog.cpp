#include "Dog.h"
#include "Cat.h"
#include "Global.h"
#include <iostream>

//extern Cat c;

//Dog d("Gunner");
void Dog::bark() {
   std::cout << "Dog rules! My name is "  << name << std::endl;
}

Dog::Dog(char* n) {
   std::cout << "Constructing Dog" << std::endl;
   name = n;
   //c.meow();
}
