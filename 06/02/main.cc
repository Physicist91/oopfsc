#include <iostream>
#include <vector>
#include "vector2.cpp"

int main(){
  NumVector a(3);
  a[0] = 1; a[1] = 2; a[2] = 3;
  NumVector b(3);
  b[0] = 4; b[1] = 5; b[2] = 6;
  NumVector c(2);
  c[0] = 10; c[1] = 9;

  try{
    //Test invalid range access
    a[a.size()] = 44;

  } catch(invalid_range e) {
    std::cout << "ERROR:" << e.what() << std::endl;
  }

  try{
    //Test invalid range access
    a[-4] = -4;

  } catch(invalid_range e) {
    std::cout << "ERROR:" << e.what() << std::endl;
  }

  try{
    //Test scalar product
    double res;
    res = a * b; //OK
    std::cout << "Product of [1, 2, 3] and [4, 5, 6] = " << res << std::endl;

  } catch(non_matching_dimension e) {
    std::cout << "ERROR:" << e.what() << std::endl;
  }

  try{
    //Test scalar product
    double res;
    res = a * c; //will fail

  } catch(non_matching_dimension e) {
    std::cout << "ERROR:" << e.what() << std::endl;
  }
}
