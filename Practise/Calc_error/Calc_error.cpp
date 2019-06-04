#include "Calc_error.h"
#include <iostream>

Calc_error::Calc_error(std::runtime_error* _ptr, std::string _cause, std::string _name, int _number): runtime_error(_cause), ptr(_ptr), name(_name), number(_number)
{}

void Calc_error::handler()
{
	try
	{
		throw;
	}
	catch(std::runtime_error* obj)
	{
		std::cout << " Zlapano wyjatek:" << std::endl;
		while(obj)
		{
			Calc_error* next = dynamic_cast<Calc_error*>(obj);
			if(next)
			{
				std::cout << " -- z powodu: " << next->what() << ", [plik = " << next->name << ", linia = " << next->number << "]" << std::endl;
				obj = next->ptr;
				delete next;
			}
			else
			{
				std::cout << " -- z powodu: " << obj->what() << std::endl;
				delete obj;
				break;
			}
		}
	}
}
