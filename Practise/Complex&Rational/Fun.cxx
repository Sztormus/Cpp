#include "Fun.hxx"
#include <iostream>
#include <cmath>

Complex Fun::Add(const Complex &a, const Complex &b)
{
	Complex obj(a.Real + b.Real, a.Imagine + b.Imagine);
	return obj;
}

Complex Fun::Multiply(const Complex &a, const Complex &b)
{
	Complex obj(a.Real * b.Real - a.Imagine * b.Imagine, a.Real * b.Imagine + a.Imagine * b.Real);
	return obj;
}

double Fun::Modulo(const Complex &a)
{
	return sqrt(a.Real * a.Real + a.Imagine * a.Imagine);
}
