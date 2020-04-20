#ifndef STATIC_COMPOSITEQUADRATURETULE_H
#define STATIC_COMPOSITEQUADRATURETULE_H

#include <utility>
#include <exception>
#include <memory>

#include "functor.h"
#include "quadrature_rule.h"

namespace Static {

template<class BaseQuadratureRule>
class CompositeQuadratureRule : public QuadratureRule<CompositeQuadratureRule<BaseQuadratureRule>>
{
public:
  CompositeQuadratureRule(const std::shared_ptr<BaseQuadratureRule>& q, unsigned int subintervals = 1)
    : _q(q)
    , _subintervals(subintervals)
  {
    if (!subintervals)
      throw std::exception();//"subintervals must be a value bigger than 0!");
  }

  template<class F>
  double integrate(const F& f, const std::pair<double, double>& domain) const
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

private:
  const std::shared_ptr<BaseQuadratureRule> _q;
  const unsigned int _subintervals;
};

} // Static

#endif // STATIC_COMPOSITEQUADRATURETULE_H
