#ifndef SINE_H
#define SINE_H

#include <utility>

#include "test_function.h"

class CompositeSine : public TestFunction
{
public:
    double operator()(double x) const override;
    double exactIntegral() const override;
};

#endif // SINE_H
