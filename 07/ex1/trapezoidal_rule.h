#ifndef TRAPEZOIDALRULE_H
#define TRAPEZOIDALRULE_H

#include <utility>

#include "functor.h"
#include "quadrature_rule.h"

class TrapezoidalRule : public QuadratureRule
{
public:
  double integrate(const Functor& f, const std::pair<double, double>& domain) const override;
};

#endif // TRAPEZOIDALRULE_H
