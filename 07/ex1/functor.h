#ifndef FUNCTOR_H
#define FUNCTOR_H

class Functor
{
public:
  virtual double operator()(double x) const = 0;
  virtual ~Functor() = default;
};

#endif //FUNCTOR_H
