#include <iostream>
#include "PrintingVisitor.h"
#include "ElData.h"

using namespace std;

void PrintingVisitor::visit(const IntData* obj)
{
	cout << " " << obj->get() << " ";
}

void PrintingVisitor::visit(const FloatData* obj)
{
	cout << " " << obj->getFloat() << " ";
}
