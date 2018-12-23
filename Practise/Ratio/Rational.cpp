#include <iostream>
#include "Rational.h"
#include <cmath>

using namespace std;

int Rational::NWD(int n1, int n2) const
{
	int c;
	int a = abs(n2);
	int b = abs(n1);
	while(b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

Rational::Rational(int n1, int n2): licznik(n1/NWD(n1, n2)), mianownik(n2/NWD(n1, n2))
{
	if(mianownik == -1)
	{
		licznik *= -1;
		mianownik *= -1;
	}
}

void Rational::Print() const
{
	if(mianownik > 1)
		cout << licznik << "/" << mianownik<< endl;
	else if(mianownik == 1)
		cout << licznik << endl;
	else
		cout << -licznik << "/" << -mianownik << endl;
}

Rational Rational::operator -() const
{
	Rational obj(-licznik, mianownik);
	return obj;
}

Rational Rational::operator +(const Rational a) const
{
	Rational obj(licznik * a.mianownik + a.licznik * mianownik, mianownik * a.mianownik);
	return obj;
}

Rational Rational::operator -(const Rational a) const
{
	Rational obj(licznik, mianownik);
	return obj + (-a);
}

Rational Rational::operator *(const Rational a) const
{
	Rational obj(licznik * a.licznik, mianownik * a.mianownik);
	return obj;
}

Rational::operator double() const
{
	double liczba = static_cast<double>(licznik)/mianownik;
	return liczba;
}
