#include <vector>
#include <iostream>
#include <cmath>
#include "vector1.cpp"

int main(){
  NumVector v(3);

  //Additional tests that I wrote
  //just wanted to make sure the constructor was OK
  // std::cout << "Size of v is " << v.size() << std::endl;
  // try{
  //   std::cout << v.at(0) << "\n";
  // }
  // catch(std::out_of_range o){
  //   std::cout<<"Out of range: "<< o.what()<<std::endl;
  // }

  v[0] = 1; v[1] = 3; v[2] = 4;
  const NumVector& w = v;
  std::cout << "norm is " << w.norm() << std::endl;
  std::cout << "vector is [" << w[0] << ", "
    << w[1] << ", " << w[2] << "]" << std::endl;
}
