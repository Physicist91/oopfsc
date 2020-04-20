#ifndef STATIC_SIMPSONRULE_H
#define STATIC_SIMPSONRULE_H

#include "quadrature_rule.h"

namespace Static {

class SimpsonRule : public QuadratureRule<SimpsonRule>
{
public:
    template<class F>
    double integrate(const F& f, const std::pair<double, double>& domain) const
    {
        {
            double dx = (domain.second-domain.first);
            return (dx / 6.0) * (f(domain.first) + 4. * f(0.5 * (domain.first + domain.second)) + f(domain.second));
        }
    }
};

namespace Inline {

class SimpsonRule : public QuadratureRule<SimpsonRule>
{
public:
    template<class F>
    inline double integrate(const F& f, const std::pair<double, double>& domain) const
    {
        {
            double dx = (domain.second-domain.first);
            return (dx / 6.0) * (f(domain.first) + 4. * f(0.5 * (domain.first + domain.second)) + f(domain.second));
        }
    }
};

}

} // Static

#endif // STATIC_SIMPSONRULE_H
