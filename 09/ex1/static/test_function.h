#ifndef STATIC_TESTFUNCTION_H
#define STATIC_TESTFUNCTION_H

#include "functor.h"

namespace Static {

template<class Imp>
class TestFunction : public Functor<Imp>
{
public:
    // TestFunction()
    double exactIntegral() const
    {
        return static_cast<const Imp&>(*this).exactIntegral();
    }
    void integrationInterval(double l, double r) const
    {
        _domain = {l, r};
    }
protected:
    mutable std::pair<double, double> _domain;
};

namespace Inline 
{

template<class Imp>
class TestFunction : public Functor<Imp>
{
public:
    // TestFunction()
    inline double exactIntegral() const
    {
        return static_cast<const Imp&>(*this).exactIntegral();
    }
    inline void integrationInterval(double l, double r) const
    {
        _domain = {l, r};
    }
protected:
    mutable std::pair<double, double> _domain;
};

} // Inline

} // Static

#endif // STATIC_TESTFUNCTION_H
