#ifndef TESTCLASS_H
#define TESTCLASS_H

#include "trapezoidal_class.h"
#include "function.h"

class TestTrapezoidal{
private:
  Functor f;
  mutable double left, right;

public:
  TestTrapezoidal(Functor& f_):f{f_}{}

  void integrationInterval(double& l, double& r) const {
    left = l;
    right = r;
  }

  double exactIntegral() const {
    //use 20 intervals
    TrapezoidalRule trapezoidal(left, right, 20);
    return trapezoidal(f);
  }

};

#endif
