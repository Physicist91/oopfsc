#ifndef STATIC_POLINOMIAL_H
#define STATIC_POLINOMIAL_H

#include <vector>

#include "test_function.h"

namespace Static {

class Polynomial : public TestFunction<Polynomial>
{
public:
  Polynomial(std::initializer_list<double> coeff) : _coeff(coeff) {}
  double operator ()(double x) const;
  double exactIntegral() const;
private:
  const std::vector<double> _coeff;
};

namespace Inline {

class Polynomial : public Static::TestFunction<Polynomial>
{
public:
  Polynomial(std::initializer_list<double> coeff) : _coeff(coeff) {}
  inline double operator()(double x) const
  {
    double result = 0.;
    double pow = 1.;
    for (int i = 0; i < _coeff.size(); ++i)
    {
      result += _coeff[i] * pow;
      pow *= x;
    }
    return result;
  }

  inline double exactIntegral() const
  {
    double result = 0.;
    double pow_l = 1.;
    double pow_r = 1.;
    for (int i = 0; i < _coeff.size(); ++i)
    { 
      pow_l *= this->_domain.first;
      pow_r *= this->_domain.second;
      result += _coeff[i] * (pow_r-pow_l)/(i+1);
    }
    return result;
  }

private:
  const std::vector<double> _coeff;
};

} // Inline
} // Static

#endif // STATIC_POLINOMIAL_H
