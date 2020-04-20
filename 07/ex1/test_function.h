#ifndef TESTFUNCTION_H
#define TESTFUNCTION_H

#include "functor.h"

class TestFunction : public Functor
{
public:
    // TestFunction()
    virtual double exactIntegral() const = 0;
    virtual void integrationInterval(double l, double r) const
    {
        _domain = {l, r};
    }
    mutable std::pair<double, double> _domain;
};

#endif // TESTFUNCTION_H
