#pragma once
#include "Complex.hxx"

class Fun
{
public:
	static Complex Add(const Complex &a, const Complex &b);
	static Complex Multiply(const Complex &a, const Complex &b);
	static double Modulo(const Complex &a);
};
