cmake_minimum_required(VERSION 3.10)
project(QuadratureRule)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Og -g")

add_executable(QuadratureRule 
        trapezoidal_rule.cc 
        simpson_rule.cc 
        composite_quadrature_rule.cc 
        polynomial.cc
        composite_sine.cc
        main.cc)
