#ifndef STATIC_ADAPTATIVECOMPOSITEQUADRATURETULE_H
#define STATIC_ADAPTATIVECOMPOSITEQUADRATURETULE_H

#include <utility>
#include <exception>
#include <list>
#include <memory>
#include <numeric>
#include <cmath>

#include "functor.h"
#include "quadrature_rule.h"

namespace Static {

template<class BaseQuadratureRule>
class AdaptativeCompositeQuadratureRule : public QuadratureRule<AdaptativeCompositeQuadratureRule<BaseQuadratureRule>>
{
public:
  AdaptativeCompositeQuadratureRule(const std::shared_ptr<BaseQuadratureRule> q, unsigned int n_adapt, double tau = 0.95, unsigned int max_it = 100, bool verbose = false)
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

  template<class F>
  double integrate(const F& f, const std::pair<double, double>& domain) const;

private:
  const std::shared_ptr<BaseQuadratureRule> _q;
  unsigned int _n_adapt;
  const double _tau;
  unsigned int _max_it;
  const bool _verbose;
};

template<class BaseQuadratureRule>
template<class F>
double AdaptativeCompositeQuadratureRule<BaseQuadratureRule>::integrate
  (
    const F& f, 
    const std::pair<double, double>& domain
  ) const
{
  if (_verbose) std::cout << "**********************************************" << std::endl;
  if (_verbose) std::cout << "Adaptative integration" << std::endl;
  if (_verbose) std::cout << "Domain: [" << domain.first << "." << domain.second << "]" << std::endl;
  if (_verbose) std::cout << std::endl;

  double x_i = domain.first;
  double x_j = domain.second;

  std::pair<double,double> subdomain = std::make_pair(x_i,x_j);

  // calculate the first interval
  std::list<double> subintervals({x_i,x_j});
  std::list<double> values(1, _q->integrate(f,subdomain));
  std::list<double> errors(1, std::numeric_limits<double>::max());

  double threshold = std::numeric_limits<double>::max();
  unsigned int count = 0;

  auto it_s = subintervals.begin();
  auto it_v = values.begin();
  auto it_e = errors.begin();

  while (values.size() < _n_adapt)
  {
    if ((*it_e) >= threshold)
    {
      // bisection on this interval
      x_i = *it_s;
      x_j = *std::next(it_s);
      double dx = (x_j - x_i)/2.;
      subintervals.insert(std::next(it_s),x_i+dx);

      // integration first new subinterval
      subdomain = std::make_pair(x_i,x_i+dx);
      double val_1 = _q->integrate(f,subdomain);

      // integration second new subinterval
      subdomain = std::make_pair(x_i+dx,x_j);
      double val_2 = _q->integrate(f,subdomain);

      double err = std::abs((*it_v) - (val_1 + val_2));
      err /= dx; // saved as density error

      // update density error (same value for both intervals)
      (*it_e) = err;
      errors.insert(std::next(it_e),err);

      // update integrals in values list
      (*it_v) = val_1;
      values.insert(std::next(it_v),val_2);
    }

    // go the the next sub-interval
    it_s++;
    it_v++;
    it_e++;

    if (it_e == errors.end())
    {
      // set a threshold as a franction of the max error.
      double max_error = (*std::max_element(errors.begin(),errors.end()));
      threshold = _tau * max_error;

      // restart iterator over intervals.
      it_s = subintervals.begin();
      it_v = values.begin();
      it_e = errors.begin();

      // if error is a minimal floating point, then it does not matter to continue the loop.
      if (threshold <= 10*std::numeric_limits<double>::epsilon())
        break;

      // ensures that this will not be an infinite loop
      count++;
      if (count >= _max_it)
        break;

      // debuggin output
      if (_verbose) 
      {
        std::cout << "*-------------------------------------------*" << std::endl;
        std::cout << "Subintervals:" << std::endl;
        for(auto it : subintervals)
          std::cout << it << " ";
        std::cout << std::endl;

        std::cout << "Values:" << std::endl;
        for(auto it : values)
          std::cout << it << " ";
        std::cout << std::endl;

        std::cout << "Errors:" << std::endl;
        for(auto it : errors)
          std::cout << it << " ";
        std::cout << std::endl;
      }
    }
  }

  if (_verbose) std::cout << "number of intervals: " << errors.size() << std::endl;
  if (_verbose) std::cout << "**********************************************" << std::endl;

  // accumulate integral over subintervals
  return std::accumulate(values.begin(),values.end(),0.);
}

} // Static

#endif // STATIC_ADAPTATIVECOMPOSITEQUADRATURETULE_H
