#ifndef STATIC_TRAPEZOIDALRULE_H
#define STATIC_TRAPEZOIDALRULE_H

#include <utility>

#include "functor.h"
#include "quadrature_rule.h"

namespace Static {

class TrapezoidalRule : public QuadratureRule<TrapezoidalRule>
{
public:
  template<class F>
  double integrate(const F& f, const std::pair<double, double>& domain) const
  {
    double dx = (domain.second-domain.first);
    return (0.5 * dx * (f(domain.first) + f(domain.second)));
  }
};

namespace Inline 
{

class TrapezoidalRule : public QuadratureRule<TrapezoidalRule>
{
public:
  template<class F>
  inline double integrate(const F& f, const std::pair<double, double>& domain) const
  {
    double dx = (domain.second-domain.first);
    return (0.5 * dx * (f(domain.first) + f(domain.second)));
  }
};

}

} // Static

#endif // STATIC_TRAPEZOIDALRULE_H
