#include <memory>
#include <iostream>
#include <iomanip>
#include <cmath>

#include "../exercise1/test_function.h"
#include "../exercise1/trapezoidal_rule.h"
#include "../exercise1/simpson_rule.h"
#include "../exercise1/composite_quadrature_rule.h"
#include "../exercise1/polynomial.h"
#include "../exercise1/composite_sine.h"
#include "adaptative_composite_quadrature_rule.h"

double conv_order(const TestFunction& f, const std::shared_ptr<QuadratureRule>& q, std::pair<double,double> domain, int n, bool adaptative = false)
{
  std::unique_ptr<QuadratureRule> composite_1, composite_2;
  if (adaptative)
  {
    composite_1 = std::make_unique<AdaptativeCompositeQuadratureRule>(q,n);
    composite_2 = std::make_unique<AdaptativeCompositeQuadratureRule>(q,2*n);
  } else {
    composite_1 = std::make_unique<CompositeQuadratureRule>(q,n);
    composite_2 = std::make_unique<CompositeQuadratureRule>(q,2*n);
  }

  // Calculate errors
  f.integrationInterval(domain.first,domain.second);
  double exact = f.exactIntegral();
  double e_n =  std::abs(exact-composite_1->integrate(f,domain));
  double e_2n = std::abs(exact-composite_2->integrate(f,domain));
  return std::log(e_n/e_2n)/std::log(2);
}

int main(int argc, char const *argv[])
{
  
  std::cout << "Enter the number of sub intervals to evaluate: "; 
  int sub_intervals;
  std::cin >> sub_intervals;
  std::cout << std::endl;

  if (not std::signbit(-1*sub_intervals))
  {
    std::cout << "Invalid input: Wrong number of subintervals" << std::endl;
    std::cout << "Using 10 sub intervals." << std::endl;
    sub_intervals = 10;
    std::cout << std::endl;
  }

  std::shared_ptr<TrapezoidalRule> trapezoidal = std::make_shared<TrapezoidalRule>();
  std::shared_ptr<CompositeQuadratureRule> composite_t = std::make_shared<CompositeQuadratureRule>(trapezoidal,sub_intervals);
  std::shared_ptr<AdaptativeCompositeQuadratureRule> adaptative_t = std::make_shared<AdaptativeCompositeQuadratureRule>(trapezoidal,sub_intervals);

  std::shared_ptr<SimpsonRule> simpson = std::make_shared<SimpsonRule>();
  std::shared_ptr<CompositeQuadratureRule> composite_s = std::make_shared<CompositeQuadratureRule>(simpson,sub_intervals);
  std::shared_ptr<AdaptativeCompositeQuadratureRule> adaptative_s = std::make_shared<AdaptativeCompositeQuadratureRule>(simpson,sub_intervals);

  std::cout << std::fixed;
  std::cout << std::setprecision(7);

  Polynomial poly({5.,0.,2.});
  std::pair<double,double> domain = {-3.,13.};

  poly.integrationInterval(domain.first,domain.second);

  std::cout << "/------------------------- Function 5+x^2 over (-3,13) -------------------------/" << std::endl;
  std::cout << "Exact integral: \t\t\t\t\t\t" << poly.exactIntegral() << std::endl;
  std::cout << std::endl;
  std::cout << "Trapezoidal rule: \t\t\t\t\t\t" << trapezoidal->integrate(poly,domain) << std::endl;
  std::cout << "Composite Trapezoidal rule (" << sub_intervals << " subintervals): \t\t\t" << composite_t->integrate(poly,domain) << std::endl;
  std::cout << "Adaptative Composite Trapezoidal rule (" << sub_intervals << " subintervals): \t" << adaptative_t->integrate(poly,domain) << std::endl;
  std::cout << std::endl;
  std::cout << "Simpson rule: \t\t\t\t\t\t\t" << simpson->integrate(poly,domain) << std::endl;
  std::cout << "Composite Simpson rule (" << sub_intervals << " subintervals): \t\t\t" << composite_s->integrate(poly,domain) << std::endl;
  std::cout << "Adaptative Composite Simpson rule (" << sub_intervals << " subintervals): \t\t" << adaptative_s->integrate(poly,domain) << std::endl;
  std::cout << std::endl;
  std::cout << "Convergence Composite Trapezoidal: \t\t\t" << conv_order(poly, trapezoidal, domain, sub_intervals) << std::endl;
  std::cout << "Convergence (Adaptative) Composite Trapezoidal: \t" << conv_order(poly, trapezoidal, domain, sub_intervals, true) << std::endl;
  std::cout << std::endl;
  std::cout << "Convergence Composite Simpson: \t\t\t\t" << conv_order(poly, simpson, domain, sub_intervals) << std::endl;
  std::cout << "Convergence (Adaptative) Composite Simpson: \t\t" << conv_order(poly, simpson, domain, sub_intervals, true) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  CompositeSine sine;
  domain = {0.,2.0*M_PI};
  sine.integrationInterval(domain.first,domain.second);

  std::cout << "/-------------------- Function (x/pi)*sin(x) over (0,2*pi) --------------------/" << std::endl;
  std::cout << "Exact integral: \t\t\t\t\t\t" << sine.exactIntegral() << std::endl;
  std::cout << std::endl;
  std::cout << "Trapezoidal rule: \t\t\t\t\t\t" << trapezoidal->integrate(sine,domain) << std::endl;
  std::cout << "Composite Trapezoidal rule (" << sub_intervals << " subintervals): \t\t\t" << composite_t->integrate(sine,domain) << std::endl;
  std::cout << "Adaptative Composite Trapezoidal rule (" << sub_intervals << " subintervals): \t" << adaptative_t->integrate(sine,domain) << std::endl;
  std::cout << std::endl;
  std::cout << "Simpson rule: \t\t\t\t\t\t\t" << simpson->integrate(sine,domain) << std::endl;
  std::cout << "Composite Simpson rule (" << sub_intervals << " subintervals): \t\t\t" << composite_s->integrate(sine,domain) << std::endl;
  std::cout << "Adaptative Composite Simpson rule (" << sub_intervals << " subintervals): \t\t" << adaptative_s->integrate(sine,domain) << std::endl;
  std::cout << std::endl;
  std::cout << "Convergence Composite Trapezoidal: \t\t\t" << conv_order(sine, trapezoidal, domain, sub_intervals) << std::endl;
  std::cout << "Convergence (Adaptative) Composite Trapezoidal: \t" << conv_order(sine, trapezoidal, domain, sub_intervals, true) << std::endl;
  std::cout << std::endl;
  std::cout << "Convergence Composite Simpson: \t\t\t\t" << conv_order(sine, simpson, domain, sub_intervals) << std::endl;
  std::cout << "Convergence (Adaptative) Composite Simpson: \t\t" << conv_order(sine, simpson, domain, sub_intervals, true) << std::endl;

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  
  std::cout << "Adaptive composite trapezoidal rule fails because of their evaluation points in bisection are zero, f({0,pi,2*pi}) = 0, "
                << "which leads to an error of 0 and therefore the abortion of quadrature adaptation." << std::endl;
  std::shared_ptr<AdaptativeCompositeQuadratureRule> adaptative_tv = std::make_shared<AdaptativeCompositeQuadratureRule>(trapezoidal,sub_intervals,0.95,100,true);
  adaptative_tv->integrate(sine,domain);
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

std::cout << std::sin(M_PI) << std::endl;

  return 0;
}