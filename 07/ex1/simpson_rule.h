#ifndef SIMPSONRULE_H
#define SIMPSONRULE_H

#include "quadrature_rule.h"

class SimpsonRule : public QuadratureRule
{
public:
    double integrate(const Functor& f, const std::pair<double, double>& domain) const override;
};

#endif // SIMPSONRULE_H
