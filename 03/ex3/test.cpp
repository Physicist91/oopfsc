#include <iostream>

int main(){
  int* p;
  p = new int;
  *p = 17;

  //p = 0;
  //delete p;

  delete p;
  p = 0;

  std::cout << p << "\n";
  
}
