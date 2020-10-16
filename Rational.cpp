#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include<fstream>
#include <math.h>

#include "Rational.h"

using namespace std;

Rational::Rational()
{
 numer=0;
 denom=1;
}

Rational::Rational(int n, int d)
{
 numer=n;
 denom=d;
}

void Rational::simplify()
{
 if (denom < 0)
 {
 numer = -numer;
 denom = -denom;
 }
 for (int i=2; i<=abs(denom) && i<=abs(numer); i++)
 if (numer % i == 0 && denom % i == 0)
 {
 numer /= i;
 denom /= i;
 i--;
 }
}


Rational& Rational::operator +=(const Rational& r)
{
 numer = (numer*r.denom+denom*r.numer);
 denom *= r.denom;
 // this - указатель на себя
 // *this - ссылка на себя
 simplify(); // упрощение
 return *this;
}

Rational Rational::operator +(const Rational &r) const
{
 // this - указатель на себя
 // *this - ссылка на себя
 Rational res(*this);
 // Используем готовую операцию добавления
 return res += r;
}

Rational Rational::operator -() const
{
 Rational r(-numer, denom);
 return r;
}

Rational& Rational::operator -=(const Rational& r)
{
 return (*this += (-r));
}

Rational Rational::operator -(const Rational &r) const
{
 // this - указатель на себя
 // *this - ссылка на себя
 Rational res(*this);
 // Используем готовую операцию добавления
 return res -= r;
}


Rational& Rational::operator ++()
{
 numer += denom;
 return *this;
}

Rational Rational::operator ++(int)
{
 Rational r(*this);
 numer += denom;
 return r;
}

bool Rational::operator ==(const Rational& r) const
{
 return (numer==r.numer) && (denom==r.denom);
}

bool Rational::operator == (const int& n) const
{
	return (numer / denom == n) && (numer % denom == 0);
}

bool Rational::operator !=(const Rational& r) const
{
 return !(*this==r);
}

bool Rational::operator < (const int& n) const
{
	return (numer / denom) < n;
}


Rational::operator int() const
{
 return numer / denom;
}

Rational::operator double() const
{
 return ((double)numer)/denom;
}

istream& operator >>(istream& in, Rational& r)
{
 in>>r.numer>>r.denom;
 return in;
}

ostream& operator <<(ostream& out, const Rational& r)
{
 out<<r.numer<<"/"<<r.denom;
 return out;
}

Rational& Rational::operator *= (const Rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}


Rational& Rational::operator *= (const int& n)
{
	numer *= n;
	simplify();
	return *this;
}

Rational Rational::operator * (const Rational& r) const
{
	Rational res(*this);
	return res *= r;
}


Rational Rational::operator * (const int& n) const
{
	Rational res(*this);
	return res *= n;
}

Rational& Rational::operator /= (const Rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}


Rational& Rational::operator /= (const int& n)
{
	denom *= n;
	simplify();
	return *this;
}

Rational Rational::operator / (const Rational& r) const
{
	Rational res(*this);
	return res /= r;
}


Rational Rational::operator / (const int& n) const
{
	Rational res(*this);
	return res /= n;
}



Rational Rational::Rsqrt() {
    Rational r(*this);
    int numer = r.numer;
    int denom = r.denom;


    Rational x0(int(sqrt(numer)),int(sqrt(denom)));
    Rational xn;
    Rational a(numer,denom);

    Rational part1;
    Rational part2;

    int i=0;

    if (x0.numer*x0.numer == numer) return x0;

    while (true){
        if(a.numer < INT_MAX/x0.denom){
            if(a.denom*2 < INT_MAX/x0.numer){
                if (x0.denom * 2 < INT_MAX){
                    part1 = a/x0;
                    part1 = part1/2;
                    x0 = x0/2;
                    if (x0.numer < INT_MAX/part1.denom && x0.denom < INT_MAX/part1.numer){
                        if (x0.numer*part1.denom < INT_MAX - part1.numer*x0.denom){
                            xn = x0 + part1;
                         } else {
                            break;
                         }
                    } else {
                        break;
                    }

                } else {
                    break;
                }
            } else {
                break;
            }
        } else {
            break;
        }

        x0 = xn;
    }

    cout<<endl<<endl<<endl;

    return xn;
}
