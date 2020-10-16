#include <iostream>
#include <cmath>
#include "Rational.cpp"

using namespace std;

int main()
{
	Rational a, b, c;

	Rational d, droot;

	Rational x1,x2;
    while (true){
	cout << "Enter the coefficient a, b, c of a quadratic equation" << endl;
	cin >> a;
/*
	d = b*b - a*c*4;

	if (d<0) {
        cout<<"no roots"<<endl;
	} else if (d==0){
        x1 = -b/2*a;
        cout<<x1<<endl;
	} else {
        droot = d.Rsqrt();

        x1 = (-b + droot)/2*a;

        x2 = (-b + droot)/2*a;

        cout<<x1<<" "<<x2<<endl;
	}
*/
	cout<<a.Rsqrt()<<endl;
    }

}
