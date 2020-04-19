#include <iostream>
#include "rationalNumber.h"

int main(){
  Rational f1 = Rational(-3,12);
  Rational f2 = Rational(4,3);
  Rational f3 = Rational(0,1);
  Rational f4;

  //Internal test functions; defined in "rationalNumber.cpp"
  //test_multip();
  //test_div();
  //test_gcd();
  //test_add();
  //test_min();
  //test_equ();

  std::cout << "f1 = -3/12, f2 = 4/3, f3 = 0/1\n";
  f4 = f1 + f2;
  std::cout << "f1 + f2 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  f4 = f1 * f2;
  std::cout << "f1 * f2 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  f4 = 4 + f2;
  std::cout << "4 + f2 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  f4 = f2 + 5;
  std::cout << "f2 + 5 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  f4 = 12 * f1;
  std::cout << "12 * f1 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  f4 = f1 * 6;
  std::cout << "f1 * 6 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  f4 = f1/f2;
  std::cout << "f1/f2 = " << f4.numerator() << "/" << f4.denominator() << "\n";
}
