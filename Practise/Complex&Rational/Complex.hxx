#pragma once

class Complex
{
	friend class Fun;
	friend class Rational;

private:
	double Real;
	double Imagine;

public:
	Complex(double n1, double n2);
	Complex(double n);
	Complex(const Complex &a);
	operator double();
	operator Complex();
	void Print() const;
	int Im() const;
	static Complex Add(const Complex &a, const Complex &b);
	static Complex Multiply(const Complex &a,const Complex &b);
	static double Modulo(const Complex &a);
};
