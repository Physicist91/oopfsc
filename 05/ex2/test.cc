#include <vector>
#include <iostream>
#include <cmath>
//#include "vector1.cpp"
#include "vector2.cpp"

void vectorTest(std::vector<double>& v){}

int main(){
  NumVector v(3);
  v.resize(2);
  vectorTest(v);
}
