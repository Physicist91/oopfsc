#include "functor.h"

double MidpointRule(Functor &f, double a = 0., double b = 1., size_t n=1000){
  double h = (b-a)/n;
  double result = 0;
  for(size_t i=0; i<n; ++i){
    result += f(a + (i + 0.5) * h);
  }
  return h*result;
}
