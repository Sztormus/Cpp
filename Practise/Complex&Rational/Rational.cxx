#include "Rational.hxx"
#include <iostream>

using namespace std;

Rational::Rational(int n1, int n2): licznik(n1), mianownik(n2){}

void Rational::Print() const
{
	cout << licznik << "/" << mianownik << endl;
}

Rational::operator Complex()
{
	Complex obj(0,0);
	obj.Real = (double)licznik/(double)mianownik;
	return obj;
}
