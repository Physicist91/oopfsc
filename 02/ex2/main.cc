#include <iostream>
#include <vector>
#include "rationalNumber.h"
#include <cmath>

//We know that first sequence is always 0/1
//We know that second sequence is always 1/N
//After some research into the properties of Farey sequence, we have the formula for the next term
//https://en.wikipedia.org/wiki/Farey_sequence#Next_term
//p = k * c - a
//q = k * d - b
//where k is the greatest integer, k <= (n+b)/d


void Farey(int N){

  Rational f1 = Rational(0, 1);
  Rational f2 = Rational(1, N);

  std::cout << "The Farey sequence of degree " << N << ":\n";
  std::cout << "(" << f1.numerator() << "/" << f1.denominator() << ", ";
  std::cout << f2.numerator() << "/" << f2.denominator();

  int p, q = N;
  while(q != 1){
    int k = floor((N + f1.denominator())/f2.denominator());
    p = k * f2.numerator() - f1.numerator();
    q = k * f2.denominator() - f1.denominator();
    std::cout << ", " << p << "/" << q;
    f1.reset_fraction(f2.numerator(), f2.denominator());
    f2.reset_fraction(p, q);
  }

  std::cout << ")\n";

}

int main(){
  Farey(1);
  Farey(2);
  Farey(3);
  Farey(4);
  Farey(5);
  Farey(6);
  Farey(7);
}
