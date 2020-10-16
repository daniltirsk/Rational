#pragma once
#ifndef _RATIONAL_H
#define _RATIONAL_H

using namespace std;

class Rational
{

 private:
     void simplify();

public:

 int numer;
 int denom;

 Rational();

 Rational(int number);

 Rational(int n, int d);

 Rational& operator +=(const Rational& r);

 Rational operator +(const Rational& r) const;

 Rational operator -() const;

 Rational& operator -=(const Rational& r);

 Rational operator -(const Rational& r) const;

 Rational& operator ++(); // префикс
 Rational operator ++(int); // постфикс

 bool operator ==(const Rational& r) const;
 bool operator == (const int& n) const;
 bool operator !=(const Rational& r) const;

 bool operator < (const int& n) const;

 operator int() const;
 operator double() const;

 friend istream& operator >>(istream& in, Rational& r);
 friend ostream& operator <<(ostream& out, const Rational& r);

 Rational& operator *= (const Rational& r);
 Rational& operator *= (const int& n);

 Rational operator * (const Rational& r) const;
 Rational operator * (const int& n) const;

 Rational& operator /= (const Rational& r);
 Rational& operator /= (const int& n);

 Rational operator / (const Rational& r) const;
 Rational operator / (const int& n) const;

 Rational Rsqrt();

};

#endif
