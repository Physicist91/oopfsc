#include "Global.h"
#include "Dog.h"
#include "Cat.h"

Dog* Global::pd = 0;
Cat* Global::pc = 0;

Global::~Global() {
   if (pd) delete pd;
   if (pc) delete pc;
}

Dog* Global::getDog() {
   if (!pd)
      return new Dog("Gunner");
   else 
      return pd;
}

Cat* Global::getCat() {
   if (!pc)
      return new Cat("Smokey");
   else 
      return pc;
}
