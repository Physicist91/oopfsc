#ifndef TEST_QUADRATURE_H
#define TEST_QUADRATURE_H

#include <utility>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <array>


template<class P, class S, class CT, class AT, class CS, class AS>
std::array<double,8> test_quadrature(
  const P& poly,
  const S& sine,
  const CT& composite_t, 
  const AT& adapt_composite_t,
  const CS& composite_s,
  const AS& adapt_composite_s,
  unsigned int its = 100 // repetitions of the experiment
) {
  std::pair<double,double> domain_poly = {-3.,13.};
  std::pair<double,double> domain_sine = {0.,2.0*M_PI};

  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::chrono::nanoseconds time_composite_t_poly(0);
  std::chrono::nanoseconds time_composite_s_poly(0);
  std::chrono::nanoseconds time_adapt_composite_t_poly(0);
  std::chrono::nanoseconds time_adapt_composite_s_poly(0);
  std::chrono::nanoseconds time_composite_t_sine(0);
  std::chrono::nanoseconds time_composite_s_sine(0);
  std::chrono::nanoseconds time_adapt_composite_t_sine(0);
  std::chrono::nanoseconds time_adapt_composite_s_sine(0);

  for (unsigned int i = 0; i < its; ++i)
  {
    start = std::chrono::high_resolution_clock::now();
    composite_t.integrate(poly,domain_poly);
    time_composite_t_poly =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);

    start = std::chrono::high_resolution_clock::now();
    composite_s.integrate(poly,domain_poly);
    time_composite_s_poly =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);
    
    start = std::chrono::high_resolution_clock::now();
    adapt_composite_t.integrate(poly,domain_poly);
    time_adapt_composite_t_poly =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);
    
    start = std::chrono::high_resolution_clock::now();
    adapt_composite_s.integrate(poly,domain_poly);
    time_adapt_composite_s_poly =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);

    start = std::chrono::high_resolution_clock::now();
    composite_t.integrate(sine,domain_sine);
    time_composite_t_sine =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);

    start = std::chrono::high_resolution_clock::now();
    composite_s.integrate(sine,domain_sine);
    time_composite_s_sine =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);
    
    start = std::chrono::high_resolution_clock::now();
    adapt_composite_t.integrate(sine,domain_sine);
    time_adapt_composite_t_sine =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);
    
    start = std::chrono::high_resolution_clock::now();
    adapt_composite_s.integrate(sine,domain_sine);
    time_adapt_composite_s_sine =+ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-start);
  }

  std::array<double,8> times;

  // mean time in microseconds for each experiment
  times[0] = (time_composite_t_poly.count()/1000.)/its;
  times[1] = (time_composite_s_poly.count()/1000.)/its;
  times[2] = (time_adapt_composite_t_poly.count()/1000.)/its;
  times[3] = (time_adapt_composite_s_poly.count()/1000.)/its;
  times[4] = (time_composite_t_sine.count()/1000.)/its;
  times[5] = (time_composite_s_sine.count()/1000.)/its;
  times[6] = (time_adapt_composite_t_sine.count()/1000.)/its;
  times[7] = (time_adapt_composite_s_sine.count()/1000.)/its;

  return  times;
}

#endif // TEST_QUADRATURE_H