#include "integrator.h"

class MidpointRule : public Integrator {
  double a,b;
  size_t n;
public:
  MidpointRule(double a_, double b_, size_t n_): a(a_),b(b_),n(n_){}

  double operator()(Functor& f) override{
    double h = (b-a)/n;

    //compute the integral boxes and sum them
    double result = 0.;
    for(size_t i=0; i<n; ++i){
      //evaluate function at midpoint and sum integral value
      result += f(a + (i + 0.5)*h);
    }

    return h*result;
  }
};
