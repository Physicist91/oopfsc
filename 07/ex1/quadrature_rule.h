#ifndef QUADRATURE_H
#define QUADRATURE_H

#include <utility>
#include <exception>

#include "functor.h"

class QuadratureRule
{
public:
  virtual double integrate(const Functor& f, const std::pair<double, double>& domain) const = 0;
};

#endif // QUADRATURE_H
