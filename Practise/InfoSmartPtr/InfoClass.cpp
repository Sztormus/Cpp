#include "InfoClass.h"
#include <iostream>
#include <string>

using namespace std;

InfoClass::InfoClass(string _name): name(_name)
{
	cout << "++ Tworze obiekt InfoClass: info = " << name << endl;
}

InfoClass::~InfoClass()
{
	cout << "++ Usuwam obiekt InfoClass: info = " << name << endl;
}

string InfoClass::info() const
{
	return "info = " + name;
}

string InfoClass::info(const string& text) const
{
	return text;
}

InfoSuperClass::InfoSuperClass(string _name, int _date): InfoClass(_name), date(_date) {}

string InfoSuperClass::info() const
{
	return "info = " + name + ", num = " + to_string(date);
}

