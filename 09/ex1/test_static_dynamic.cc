#include <memory>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <array>

#include "static/trapezoidal_rule.h"
#include "static/simpson_rule.h"
#include "static/composite_quadrature_rule.h"
#include "static/adaptative_composite_quadrature_rule.h"

#include "../../sheet07/exercise1/polynomial.h"
#include "../../sheet07/exercise1/composite_sine.h"

#include "test_static_dynamic.hh"
#include "test_quadrature.hh"

std::array<double,8> test_static_dynamic(unsigned int sub_intervals, unsigned int its)
{
  std::shared_ptr<Static::TrapezoidalRule> trapezoidal = std::make_shared<Static::TrapezoidalRule>();
  Static::CompositeQuadratureRule<Static::TrapezoidalRule> composite_t(trapezoidal,sub_intervals);
  Static::AdaptativeCompositeQuadratureRule<Static::TrapezoidalRule> adapt_composite_t(trapezoidal,sub_intervals);

  std::shared_ptr<Static::SimpsonRule> simpson = std::make_shared<Static::SimpsonRule>();
  Static::CompositeQuadratureRule<Static::SimpsonRule> composite_s(simpson,sub_intervals);
  Static::AdaptativeCompositeQuadratureRule<Static::SimpsonRule> adapt_composite_s(simpson,sub_intervals);

  Dynamic::Polynomial poly({5.,0.,2.});
  CompositeSine sine;

  return test_quadrature<Functor,Functor>(poly, sine, composite_t, adapt_composite_t, composite_s, adapt_composite_s, its);
}

std::array<double,8> test_static_dynamic_inline(unsigned int sub_intervals, unsigned int its)
{
  std::shared_ptr<Static::Inline::TrapezoidalRule> trapezoidal = std::make_shared<Static::Inline::TrapezoidalRule>();
  Static::CompositeQuadratureRule<Static::Inline::TrapezoidalRule> composite_t(trapezoidal,sub_intervals);
  Static::AdaptativeCompositeQuadratureRule<Static::Inline::TrapezoidalRule> adapt_composite_t(trapezoidal,sub_intervals);

  std::shared_ptr<Static::Inline::SimpsonRule> simpson = std::make_shared<Static::Inline::SimpsonRule>();
  Static::CompositeQuadratureRule<Static::Inline::SimpsonRule> composite_s(simpson,sub_intervals);
  Static::AdaptativeCompositeQuadratureRule<Static::Inline::SimpsonRule> adapt_composite_s(simpson,sub_intervals);

  Dynamic::Polynomial poly({5.,0.,2.});
  CompositeSine sine;

  return test_quadrature<Functor,Functor>(poly, sine, composite_t, adapt_composite_t, composite_s, adapt_composite_s, its);
}