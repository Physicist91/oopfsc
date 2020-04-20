#include <memory>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <array>

#include "../../sheet07/exercise1/trapezoidal_rule.h"
#include "../../sheet07/exercise1/simpson_rule.h"
#include "../../sheet07/exercise1/composite_quadrature_rule.h"
#include "../../sheet07/exercise2/adaptative_composite_quadrature_rule.h"

#include "../../sheet07/exercise1/polynomial.h"
#include "../../sheet07/exercise1/composite_sine.h"

#include "test_dynamic_dynamic.hh"
#include "test_quadrature.hh"

std::array<double,8> test_dynamic_dynamic(unsigned int sub_intervals, unsigned int its)
{
  std::shared_ptr<TrapezoidalRule> trapezoidal = std::make_shared<TrapezoidalRule>();
  CompositeQuadratureRule composite_t(trapezoidal,sub_intervals);
  AdaptativeCompositeQuadratureRule adapt_composite_t(trapezoidal,sub_intervals);

  std::shared_ptr<SimpsonRule> simpson = std::make_shared<SimpsonRule>();
  CompositeQuadratureRule composite_s(simpson,sub_intervals);
  AdaptativeCompositeQuadratureRule adapt_composite_s(simpson,sub_intervals);

  Dynamic::Polynomial poly({5.,0.,2.});
  CompositeSine sine;

  return test_quadrature(poly, sine, composite_t, adapt_composite_t, composite_s, adapt_composite_s, its);
}