#include "polynomial.h"

namespace Dynamic {

double Polynomial::operator()(double x) const
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

double Polynomial::exactIntegral() const
{
  double result = 0.;
  double pow_l = 1.;
  double pow_r = 1.;
  for (int i = 0; i < _coeff.size(); ++i)
  { 
    pow_l *= _l;
    pow_r *= _r;
    result += _coeff[i] * (pow_r-pow_l)/(i+1);
  }
  return result;
}

} // Dynamic