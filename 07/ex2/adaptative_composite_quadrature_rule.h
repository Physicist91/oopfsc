#ifndef ADAPTATIVECOMPOSITEQUADRATURETULE_H
#define ADAPTATIVECOMPOSITEQUADRATURETULE_H

#include <utility>
#include <exception>
#include <memory>

#include "../exercise1/functor.h"
#include "../exercise1/quadrature_rule.h"

class AdaptativeCompositeQuadratureRule : public QuadratureRule
{
public:
  AdaptativeCompositeQuadratureRule(const std::shared_ptr<QuadratureRule> q, unsigned int n_adapt, double tau = 0.95, unsigned int max_it = 100, bool verbose = false)
    : _q(q)
    , _n_adapt(n_adapt)
    , _tau(tau)
    , _max_it(max_it)
    , _verbose(verbose)
  {
    if (!_n_adapt)
      throw std::exception();//'number of subintervals must be a value bigger than 0!');
    if (_tau >=1.0 or _tau <= 0.0)
      throw std::exception();
  }

  double integrate(const Functor& f, const std::pair<double, double>& domain) const override;

private:
  const std::shared_ptr<QuadratureRule> _q;
  unsigned int _n_adapt;
  const double _tau;
  unsigned int _max_it;
  const bool _verbose;
};

#endif // ADAPTATIVECOMPOSITEQUADRATURETULE_H
