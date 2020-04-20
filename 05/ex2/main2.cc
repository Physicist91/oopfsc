#include <vector>
#include <iostream>
#include <cmath>
#include "vector2.cpp"

int main(){
  NumVector v(3);

  v[0] = 1; v[1] = 3; v[2] = 4;
  const NumVector& w = v;
  std::cout << "norm is " << w.norm() << std::endl;
  std::cout << "vector is [" << w[0] << ", "
    << w[1] << ", " << w[2] << "]" << std::endl;
}
