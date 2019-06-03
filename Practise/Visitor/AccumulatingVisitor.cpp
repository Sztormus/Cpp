#include <iostream>
#include "AccumulatingVisitor.h"
#include "ElData.h"

using namespace std;

void AccumulatingVisitor::visit(const IntData* obj)
{
	sum += obj->get();
}

void AccumulatingVisitor::visit(const FloatData* obj)
{
	sum += obj->getFloat();
}

float AccumulatingVisitor::getTotalSum() const
{
	return sum;
}
