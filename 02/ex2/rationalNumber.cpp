#include <iostream>
#include "rationalNumber.h"
#include <cmath>
#include <stdexcept>

//Adding two extra member functions
void Rational::reset_fraction(int num_, int den_){
  num = num_;
  den = den_;
  reduce();
}


/********************************************************************/
/* Defining GCD and LCM */
/*------------------------------------------------------------------*/

//implement GCD using the Euclidean algorithm
//recursive-style
unsigned int gcd(int left_, int right_){
  unsigned int right = std::abs(right_);
  unsigned int left = std::abs(left_);
  if(right > left) std::swap(left, right);
  unsigned int r = left%right;
  // while( (r = left%right) != 0) {
  //   left = right;
  //   right = r;
  // }
  if(r == 0) return right;
  else return gcd(right, r);
}

//implement LCM
unsigned int lcm(int left_, int right_){
  unsigned int right = std::abs(right_);
  unsigned int left = std::abs(left_);

  //Properties of LCM and GCD: LCM * GCD = a * b
  return left/gcd(left, right) * right;

}

/***********************************************************************/
/* Definition of member functions */
/**********************************************************************/

void Rational::reduce() {
  int gcd_ = gcd(num, den);
  num /= gcd_;
  den /= gcd_;
}

Rational::Rational(){
  num = 1;
  den = 1;
}

Rational::Rational(int whole) {

  num = whole;
  den = 1;
}

Rational::Rational(int num_, int den_){

  //Check for valid input
  if(num_==0) {
    num = num_;
    den = den_;
  } else if(den_==0){
    throw std::out_of_range("invalid denominator");
  } else {
    num = num_;
    den = den_;
    reduce();
  }

}

int Rational::numerator() const{
  return num;
}

int Rational::denominator() const{
  return den;
}

Rational Rational::operator*=(Rational obj){
  //The trick is to simplify the fractions before multiplying
  //This is more efficient, robust to overflow
  Rational left = Rational(this->num, obj.den);
  Rational right = Rational(obj.num, this->den);
  num = left.num * right.num;
  den = left.den * right.den;

  return *this;
}

Rational Rational::operator/=(Rational obj){
  Rational temp = Rational(obj.den, obj.num);
  return *this*=temp;
}

Rational Rational::operator+=(Rational obj){
  //The trick here is to do the division before the multiplication
  //This trick is more robust to overflow
  unsigned int lcm_ = lcm(this->den, obj.den);
  num = this->num * (lcm_/this->den) + obj.num * (lcm_/obj.den);
  den = lcm_;
  reduce();
  return *this;
}

Rational Rational::operator-=(Rational obj){
  //The trick here is to do the division before the multiplication
  //This trick is more robust to overflow
  unsigned int lcm_ = lcm(this->den, obj.den);
  num = this->num * (lcm_/this->den) - obj.num * (lcm_/obj.den);
  den = lcm_;
  reduce();
  return *this;
}

/**************************************************************************/
/* Defining other useful operators */
/*------------------------------------------------------------------------*/

bool operator==(Rational left_, Rational right_){
  Rational left = Rational(left_.numerator(),left_.denominator());
  Rational right = Rational(right_.numerator(),right_.denominator());
  bool sign1 = left.numerator()/left.denominator() > 0;
  bool sign2 = right.numerator()/right.denominator() > 0;
  return std::abs(left.numerator()) == std::abs(right.numerator()) && std::abs(left.denominator()) == std::abs(right.denominator()) && !(sign1 ^ sign2);
}

Rational operator+(Rational left, Rational right) {
  return left+=right;
}

Rational operator-(Rational left, Rational right) {
  return left-=right;
}

Rational operator*(Rational left, Rational right) {
  return left*=right;
}

Rational operator/(Rational left, Rational right) {
  return left/=right;
}

/*****************************************************************/
/* Test functions        */
/* --------------------------------------------------------------*/

//function to test the GCD algorithm
void test_gcd(){
  int d, e;
  std::cout << "Enter a number:\n";
  std::cin >> d;
  std::cin >> e;
  std::cout << "The GCD is " << gcd(d,e) << "\n";
}

//function to test the *= operator
void test_multip() {
  Rational f2 = Rational(2,3);
  Rational f4 = Rational(2,10);
  f4 *= f4;
  std::cout << "Own multiplication of 2/10 is " << f4.numerator() << "/" << f4.denominator() << "\n";
  f2 *= f2;
  std::cout << "Own multiplication of 2/3 is " << f2.numerator() << "/" << f2.denominator() << "\n";
  f4 *= f2;
  std::cout << "Cross multiplication is " << f4.numerator() << "/" << f4.denominator() << "\n";
}

//function to test the /= operator
void test_div(){
  Rational f2 = Rational(2,3);
  Rational f4 = Rational(2,10);
  f2 /= f4;
  std::cout << "2/3 : 2/10 is " << f2.numerator() << "/" << f2.denominator() << "\n";
  f4 /= f2;
  std::cout << "2/10 : 10/3 is " << f4.numerator() << "/" << f4.denominator() << "\n";

}

//function to test the += operator
void test_add(){
  Rational f4 = Rational(1, 2);
  Rational f5 = Rational(3, 4);
  Rational f6 = Rational(-5,6);

  f4+=f5;
  std::cout << "1/2 + 3/4 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  f4 = f5 + f6;
  std::cout << "3/4 + -5/6 = " << f4.numerator() << "/" << f4.denominator() << "\n";
}

void test_min(){
  Rational f4 = Rational(1, 2);
  Rational f5 = Rational(3, 4);
  Rational f6 = Rational(-5,6);

  f4-=f5;
  f5-=f6;
  std::cout << "1/2 - 3/4 = " << f4.numerator() << "/" << f4.denominator() << "\n";
  std::cout << "3/4 - (-5/6) = " << f5.numerator() << "/" << f5.denominator() << "\n";
}

void test_equ(){
  Rational f4 = Rational(-1,2);
  Rational f5 = Rational(1,-2);
  Rational f6 = Rational(3,4);

  if(f4==f4){
    std::cout << "case 1: -1/2 = -1/2\n";
  } else {
    std::cout << "case 1: -1/2 != -1/2\n";
  }

  if(f4==f5){
    std::cout << "case 2: -1/2 = -1/2\n";
  } else {
    std::cout << "case 2: -1/2 != -1/2\n";
  }

  if(f4 == f6){
    std::cout << "different fractions, got equal\n";
  } else {
    std::cout << "different fractions, got different\n";
  }
}
