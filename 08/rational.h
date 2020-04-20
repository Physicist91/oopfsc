#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <exception>
#include <cmath>


class Rational
{
public:
    Rational();
    Rational(int numerator, int denominator);
    Rational(int whole_nr);

    int numerator() const {return num;}
    int denominator()const {return den;}

    bool operator==(const Rational & a) const;
    Rational& operator*=(const Rational & a);
    Rational& operator *=(const int& a);
    Rational& operator/=(const Rational & a);
    Rational& operator /=(const int& a);
    Rational& operator+=(const Rational & a);
    Rational& operator +=(const int& a);
    Rational& operator-=(const Rational & a);
    Rational& operator -=(const int& a);
    // way to allow usage of std::cout << <Rational fraction>;
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) ;

private:
    int num;
    int den;
    int gcd(int n, int d) const; // greatest common divisor recursively
    void simplify();
};


Rational operator +(const Rational& a, const Rational& b);
Rational operator +(int a, Rational& b);
Rational operator +(Rational& b, int a);

Rational operator *(const Rational& a, const Rational& b);
Rational operator *(int a, Rational& b);
Rational operator *(Rational& b, int a);

Rational operator /(Rational& a, Rational& b);
Rational operator /(int a, Rational& b);
Rational operator /(Rational& a, int b);

Rational operator -(const Rational& a, const Rational& b);
Rational operator -(int a, Rational& b);
Rational operator -(Rational& a, int b);

bool operator==(Rational& a, int b);
bool operator==(int a, Rational b);


class bad_math_exception : public std::exception
{
public:
    virtual const char* what() const throw()
      {
        return "You tried to initialize a fraction with 0 in the denominator!";
      }
};

#endif // RATIONAL_H
