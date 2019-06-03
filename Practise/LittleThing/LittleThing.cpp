#include <iostream>
#include "LittleThing.h"

using namespace std;

bool LittleThing::flag = true;
LittleThing* LittleThing::tab = NULL;
int LittleThing::n = 0;

LittleThing::LittleThing()
{
	value = 0;
}

LittleThing::LittleThing(int _value)
{
	cout << "Konstrukcja Malenstwa: wart = " << _value << endl;
	value = _value;
}

int& LittleThing::Value()
{
	return value;
}

void* LittleThing::operator new(long unsigned int size)
{
	cout << "Alokuje jeden obiekt: " << size/4 << " (" << size << " bajtow)" << endl;
	if(flag)
	{
		flag = false;
		cout << "Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow" << endl;
		tab = ::new LittleThing[100];
	}
	n++;
	return &tab[n - 1];
}

void* LittleThing::operator new[](long unsigned int size)
{
 	cout << "Alokuje tablice [] o rozmiarze: " << (size - 8)/4 << " (" << size << " bajtow)" << endl;
	n += (size - 8)/4;
	return &tab[n - (size - 8)/4 - 1];
}
void LittleThing::operator delete(void* ptr, long unsigned int size)
{
	cout << "Zwalniam jeden obiekt: " << size/4 << " (" << size << " bajtow)" << endl;
	tab[n - 1].value = 0;
	n--;
	if(n == 0)
		::delete[] tab;
}
void LittleThing::operator delete[](void* ptr, long unsigned int size)
{
	cout << "Zwalniam tablice [] o rozmiarze: " << (size - 8)/4 << " (" << size << " bajtow)" << endl;
	for(unsigned int i = 0; i < (size - 8)/4; i++)
		tab[n - 1 - (size - 8)/4 + 1].value = 0;
	if(n == 0)
		::delete[] tab;
}

LittleThing::~LittleThing()
{
	if(n > 0)
		n--;
	else
		::delete tab;
}

LittleThingCleaner::LittleThingCleaner(LittleThing* obj): ptr(obj) {}

LittleThingCleaner::~LittleThingCleaner()
{
	delete ptr;
}

const LittleThing* LittleThingCleaner::operator ->() const
{
	return ptr;
}

LittleThing* LittleThingCleaner::operator ->()
{
	return ptr;
}
