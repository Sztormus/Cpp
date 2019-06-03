#include "InfoSmartPtr.h"
#include <iostream>

using namespace std;

InfoSmartPtr::InfoSmartPtr(InfoClass *temp): ptr(temp), number(new int)
{
	*number = 1;
}

InfoSmartPtr::InfoSmartPtr(const InfoSmartPtr& obj): ptr(obj.ptr), number(obj.number)
{
	*number = *number + 1;
}

InfoSmartPtr::~InfoSmartPtr()
{
	check_number();
}

const InfoClass& InfoSmartPtr::operator*() const
{
	return *ptr;
}

const InfoClass* InfoSmartPtr::operator->() const
{
	return ptr;
}

InfoClass& InfoSmartPtr::operator*()
{
	return *ptr;
}

InfoClass* InfoSmartPtr::operator->()
{
	return ptr;
}

void InfoSmartPtr::operator=(const InfoSmartPtr& obj)
{
	check_number();
	ptr = obj.ptr;
	number = obj.number;
	(*number)++;
}

void InfoSmartPtr::check_number()
{
	(*number)--;
	if((*number) == 0)
	{
		delete number;
		delete ptr;
	}

}
