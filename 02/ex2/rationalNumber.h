/* implement a class for rational numbers */

class Rational {
private:
  int num;
  int den;

  //function to reduce(simplify) fractions
  void reduce();

public:
  Rational();
  Rational(int whole);
  Rational(int num_, int den_);

  int numerator() const;
  int denominator() const;
  void reset_fraction(int num_, int den_);


  Rational operator*=(Rational obj);
  Rational operator/=(Rational obj);
  Rational operator+=(Rational obj);
  Rational operator-=(Rational obj);
};

Rational operator+(Rational left, Rational right);

Rational operator-(Rational left, Rational right);

Rational operator*(Rational left, Rational right);

Rational operator/(Rational left, Rational right);


//Definitions of test functions
void test_equ();
void test_multip();
void test_div();
void test_gcd();
void test_add();
void test_min();
