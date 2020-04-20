
class Dog;
class Cat;

class Global {
   static Dog* pd;
   static Cat* pc;

public:
//   Global() {
//      pd = 0;
//      pc = 0;
//   }

   ~Global();

   static Dog* getDog();

   static Cat* getCat();
};
