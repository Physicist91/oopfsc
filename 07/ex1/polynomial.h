#ifndef POLINOMIAL_H
#define POLINOMIAL_H

#include <vector>

#include "test_function.h"

namespace Dynamic {

class Polynomial : public TestFunction
{
public:
  Polynomial(std::initializer_list<double> coeff) : _coeff(coeff) {}
  double operator ()(double x) const override;

  void integrationInterval(double l, double r) const override
  {
    _l = l;
    _r = r;
  }
  double exactIntegral() const override;
private:
  const std::vector<double> _coeff;
  mutable double _l, _r;
};

} // Dynamic

#endif // POLINOMIAL_H
