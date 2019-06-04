#include "LicznikPoziomow.h"
#include <iostream>

int LicznikPoziomow::level = 0;

LicznikPoziomow::LicznikPoziomow()
{
	++level;
	std::cout << "Rozpoczynamy poziom numer " << level << "." << std::endl;
}

LicznikPoziomow::~LicznikPoziomow()
{
	std::cout << "Konczymy poziom numer " << level << "." << std::endl;
	--level;
}
