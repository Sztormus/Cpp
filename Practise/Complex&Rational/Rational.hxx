#pragma once
#include "Complex.hxx"

class Rational
{
	friend class Complex;
	
private:
	int licznik;
	int mianownik;

public:
	Rational(int n1, int n2);
	void Print() const;
	operator Complex();
};

