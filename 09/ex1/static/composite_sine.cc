#include "composite_sine.h"
#include <cmath>

namespace Static {

double CompositeSine::operator ()(double x) const
{
    return std::sin(x) * x / M_PI;
}

double CompositeSine::exactIntegral() const
{
    return (std::sin(_domain.second) - _domain.second * std::cos(_domain.second) / M_PI) 
         - (std::sin(_domain.first) - _domain.first * std::cos(_domain.first)/M_PI);
}

} // Static