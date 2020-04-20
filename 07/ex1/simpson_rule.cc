#include "simpson_rule.h"

double SimpsonRule::integrate(const Functor& f, const std::pair<double, double>& domain) const
{
  double dx = (domain.second-domain.first);
  return (dx / 6.0) * (f(domain.first) + 4. * f(0.5 * (domain.first + domain.second)) + f(domain.second));
}