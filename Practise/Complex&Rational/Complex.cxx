#include "Complex.hxx"
#include <iostream>

using namespace std;

Complex::Complex(double n1 = 0, double n2 = 0): Real(n1), Imagine(n2){}

Complex::Complex(double n = 0): Real(n), Imagine(0){}

Complex::Complex(const Complex &a): Real(a.Real), Imagine(a.Imagine){}

Complex::operator double()
{
	return Real;
}

void Complex::Print() const
{
	if(Imagine != 0)
		cout << Real << "+" << Imagine << "i" << endl;
	else
		cout << Real << endl;
}

int Complex::Im() const
{
	return Imagine;
}
