#ifndef COMPOSITEQUADRATURETULE_H
#define COMPOSITEQUADRATURETULE_H

#include <utility>
#include <exception>
#include <memory>

#include "functor.h"
#include "quadrature_rule.h"

class CompositeQuadratureRule : public QuadratureRule
{
public:
  CompositeQuadratureRule(const std::shared_ptr<QuadratureRule>& q, unsigned int subintervals = 1)
    : _q(q)
    , _subintervals(subintervals)
  {
    if (!subintervals)
      throw std::exception();//"subintervals must be a value bigger than 0!");
  }

  double integrate(const Functor& f, const std::pair<double, double>& domain) const override;

private:
  const std::shared_ptr<QuadratureRule> _q;
  unsigned int _subintervals;
};

#endif // COMPOSITEQUADRATURETULE_H
