#include <iostream>

class Empty {

};

class EmptyDerived:public Empty {

};

class NonEmpty:public Empty{
  char c;
};

struct Composite{
  Empty a;
  int b;
};

struct Composite2{
  Empty a;
  char b;
};

int main(){
  std::cout << "Sizeof Empty: " << sizeof(Empty) << "\n";
  std::cout << "Sizeof EmptyDerived: " << sizeof(EmptyDerived) << "\n";
  std::cout << "Sizeof NonEmpty: " << sizeof(NonEmpty) << "\n";

  Composite c;
  std::cout << "Address of a: " << &c.a << "\n";
  std::cout << "Sizeof a: " << sizeof(c.a) << "\n";
  std::cout << "Address of b: " << &c.b << "\n";
  std::cout << "Sizeof b: " << sizeof(c.b) << "\n";
  Composite2 c2;
  std::cout << "Sizeof b2: " << sizeof(c2.b) << "\n";
}
