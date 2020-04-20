#include "rational.h"

/******************************************************************************/
// Constructors
/******************************************************************************/

Rational::Rational(int numerator, int denominator)
  : num(numerator)
  , den(denominator)
{
    //make sure no Rational with a denominator 0 is instantiated
    if(denominator == 0)
    {
        throw bad_math_exception();
    }
    simplify();
}

Rational::Rational()
  : num(1)
  ,  den(1)
{}

Rational::Rational(int whole_nr)
  : num(whole_nr)
  , den(1)
{}


/******************************************************************************/
// Class Methods
/******************************************************************************/

int Rational::gcd(int n, int d) const
{
  if(d == 0)
    return n;
  else
    return gcd(d, n % d);
}

void Rational::simplify()
{
    int sign = std::signbit(num * den) ? -1 : 1;
    int dev = gcd(num, den);
    num = sign * std::abs(num / dev);
    den = std::abs(den / dev);
}

/******************************************************************************/
// Operators
/******************************************************************************/

bool Rational::operator ==(const Rational& a) const
{
  return (a.numerator() == num && a.denominator() == den);
}


Rational& Rational::operator *=(const Rational& a)
{
    num *= a.numerator();
    den *= a.denominator();
    simplify();
    return (*this);
}

Rational& Rational::operator *=(const int& a)
{
    Rational tmp = Rational(a);
    *this *= tmp;
    return (*this);
}

Rational& Rational::operator /=(const Rational& a)
{
    Rational b = Rational(a.denominator(), a.numerator());
    *this *= b;
    return (*this);
}

Rational& Rational::operator /=(const int& a)
{
    Rational tmp = Rational(a);
    *this /= tmp;
    return (*this);
}

Rational& Rational::operator +=(const Rational& a)
{
    if(a.denominator() == den)
        num += a.numerator();
    else {
        num *= a.denominator();
        num += a.numerator() * den;
        den *= a.denominator();
    }
    simplify();
    return (*this);
}

Rational& Rational::operator +=(const int& a)
{
    Rational tmp = Rational(a);
    *this += tmp;
    return (*this);
}

Rational& Rational::operator -=(const Rational& a)
{
    Rational b = Rational(-1*a.numerator(), a.denominator());
    *this += b;
    return (*this);
}

Rational& Rational::operator -=(const int& a)
{
    Rational tmp = Rational(a);
    *this -= tmp;
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Rational& r) 
{
    os << r.numerator() << '/' << r.denominator();
    return os;
}


/******************************************************************************/
// global operators (to allow e.g. 1 + Rational)
/******************************************************************************/
bool operator==(const Rational& a, const int& b)
{
  if(a.denominator()==1)
    return (a.numerator()==b);
  else
    return false;
};

bool operator==(const int& a, const Rational& b)
{
  return (b==a);
};


Rational operator +(const Rational& a, const Rational& b)
{
    Rational tmp = a;
    tmp += b;
    return tmp;
}

Rational operator +(int a, Rational& b)
{
    Rational tmp = Rational(a);
    tmp += b;
    return tmp;
}

Rational operator +(Rational& b, int a)
{
    Rational tmp = Rational(a);
    tmp += b;
    return tmp;
}


Rational operator *(const Rational& a, const Rational& b)
{
    Rational tmp = a;
    tmp *= b;

    return tmp;
}

Rational operator *(int a, Rational& b)
{
    Rational tmp = Rational(a);
    tmp *= b;
    return tmp;
}

Rational operator *(Rational& b, int a)
{
    Rational tmp = Rational(a);
    tmp *= b;
    return tmp;
}


Rational operator /(Rational& a, Rational& b)
{
    Rational tmp = a;
    tmp /= b;
    return tmp;
}

Rational operator /(int a, Rational& b)
{
    Rational tmp = Rational(a);
    tmp /= b;
    return tmp;
}

Rational operator /(Rational& a, int b)
{
    Rational tmp = b;
    Rational tmp2 = Rational(a);
    tmp /= tmp2;
    return tmp;
}


Rational operator -(const Rational& a, const Rational& b)
{
    Rational tmp = a;
    tmp -= b;
    return tmp;
}

Rational operator -(int a, Rational& b)
{
    Rational tmp = Rational(a);
    tmp -= b;
    return tmp;
}

Rational operator -(Rational& a, int b)
{
    Rational tmp = b;
    Rational tmp2 = Rational(b);
    tmp -= tmp2;
    return tmp;
}
