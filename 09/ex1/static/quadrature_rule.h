#ifndef STATIC_QUADRATURE_H
#define STATIC_QUADRATURE_H

#include <utility>
#include <exception>

#include "functor.h"

namespace Static {

template<class Imp>
class QuadratureRule
{
public:
  template<class F>
  double integrate(const F& f, const std::pair<double, double>& domain) const
  {
    return static_cast<const Imp&>(*this).integrate(f,domain);
  }
};

namespace Inline {

template<class Imp>
class QuadratureRule
{
public:
  template<class F>
  inline double integrate(const F& f, const std::pair<double, double>& domain) const
  {
    return static_cast<const Imp&>(*this).integrate(f,domain);
  }
};

} // Inline

} // Static

#endif // STATIC_QUADRATURE_H
