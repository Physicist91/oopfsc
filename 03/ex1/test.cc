#include <iostream>

int main(){


  int i=1;
  int j[3] = {0, 1, 2};
  int* p=&j[1];

  std::cout << i + 1 << "\n";
  std::cout << *p << "\n";
  std::cout << *p + 3 << "\n";
  std::cout << (&i == p) << "\n";
  std::cout << (i == *p) << "\n";
  std::cout << &p << "\n";
  std::cout << p << "\n";
  std::cout << **(&p) << "\n";
}
