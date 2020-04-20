#include "composite_quadrature_rule.h"

double CompositeQuadratureRule::integrate(const Functor& f, const std::pair<double, double>& domain) const
{
  double rhs = 0.0;
  double x_i = domain.first;
  double x_j = domain.second;
  double dx = (x_j - x_i)/_subintervals;

  for (int i = 0; i < _subintervals; ++i)
  {
    std::pair<double,double> subdomain = std::make_pair(x_i,x_i+dx);
    rhs += _q->integrate(f,subdomain);
    x_i = x_i+dx;
  }
  return rhs;
}