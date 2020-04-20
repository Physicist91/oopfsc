#include <iostream>
#include "midpoint.h"
#include "test_functions.h"

int main(){
  Cosine cosine(1.,-1.);
  std::cout << "Integral of cos(x-1) in "
  << "the interval [1:pi/2+1] is "
  << MidpointRule(cosine, 1.,M_PI_2+1.) << std::endl;
  return 0;
}
