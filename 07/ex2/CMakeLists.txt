cmake_minimum_required(VERSION 3.10)
project(AdaptativeQuadratureRule)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Og -g")

add_executable(AdaptativeQuadratureRule 
        ../exercise1/trapezoidal_rule.cc 
        ../exercise1/simpson_rule.cc 
        ../exercise1/composite_quadrature_rule.cc 
        ../exercise1/polynomial.cc
        ../exercise1/composite_sine.cc
        adaptative_composite_quadrature_rule.cc
        main.cc)
