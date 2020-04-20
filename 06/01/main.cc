#include <iostream>
#include <string>
#include <exception>

class my_exception : public std::exception {
size_t sz;
char* err;
public:
  my_exception(std::string e):sz{e.length()}{
    err = new char[sz];
    for(int i=0; i<sz; ++i) err[i] = e[i];
  }

  const char* what() const noexcept {
    return err;
  }
};

//Class Foo throws in the destructor
class Foo {
public:
  ~Foo() {
    throw my_exception("Foo exception");
  }
};

//Class Bar throws in the constructor
class Bar {
public:
  Bar() {
    throw my_exception("Bar exception");
  }
};

int main(){
  try {
    Foo f;
    Bar b;
  }
  catch (const std::exception & e){
    std::cout << "ERROR:" << e.what() << std::endl;
  }
}
