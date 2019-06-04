#include "NumerId.h"
#include <iostream>
#include <iomanip>

NumerId::NumerId(int value): number(value) {}

std::ostream& operator << (std::ostream& os, const NumerId& obj)
{
	return os << "<" << std::setw(6) << std::setfill('0') << obj.number << ">";
}

const NumerId& NumerId::numId() const
{
	return *this;
}
