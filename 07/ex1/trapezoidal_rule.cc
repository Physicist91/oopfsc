
#include "trapezoidal_rule.h"

double TrapezoidalRule::integrate(const Functor& f, const std::pair<double, double>& domain) const
{
  double dx = (domain.second-domain.first);
  return (0.5 * dx * (f(domain.first) + f(domain.second)));
}