#ifndef STATIC_FUNCTOR_H
#define STATIC_FUNCTOR_H

namespace Static {

template<class Imp>
class Functor
{
public:
  inline double operator()(double x) const
  {
    return static_cast<const Imp&>(*this).operator()(x);
  }
};

namespace Inline
{

template<class Imp>
class Functor
{
public:
  inline double operator()(double x) const
  {
    return static_cast<const Imp&>(*this).operator()(x);
  }
};

} // Inline

} // Static

#endif //STATIC_FUNCTOR_H
