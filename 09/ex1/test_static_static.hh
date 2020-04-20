#ifndef TEST_STATIC_STATIC_H
#define TEST_STATIC_STATIC_H

#include <array>

std::array<double,8> test_static_static(unsigned int sub_intervals = 10000, unsigned int its = 100);
std::array<double,8> test_static_static_inline(unsigned int sub_intervals = 10000, unsigned int its = 100);

#endif // TEST_STATIC_STATIC_H