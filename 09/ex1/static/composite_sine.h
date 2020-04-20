#ifndef STATIC_SINE_H
#define STATIC_SINE_H

#include <utility>
#include <cmath>

#include "test_function.h"

namespace Static {

class CompositeSine : public TestFunction<CompositeSine>
{
public:
    double operator()(double x) const;
    double exactIntegral() const;
};

namespace Inline {

class CompositeSine : public TestFunction<CompositeSine>
{
public:
    inline double operator()(double x) const;
    inline double exactIntegral() const;
};

inline double CompositeSine::operator ()(double x) const
{
    return std::sin(x) * x / M_PI;
}

inline double CompositeSine::exactIntegral() const
{
    return (std::sin(_domain.second) - _domain.second * std::cos(_domain.second) / M_PI) 
         - (std::sin(_domain.first) - _domain.first * std::cos(_domain.first)/M_PI);
}

} // Inline

} // Static

#endif // STATIC_SINE_H
