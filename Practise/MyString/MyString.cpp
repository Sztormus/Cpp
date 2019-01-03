#include <iostream>
#include "MyString.h"
#include <cstring>

using namespace std;

MyString::MyString(): tab(NULL), length(0) {}

MyString::MyString(const char* napis): tab(new char[strlen(napis) + 1]), length(strlen(napis))
{
	strcpy(tab, napis);
}

MyString::~MyString()
{
	delete[] tab;
}

void MyString::Print() const
{
	cout << tab << endl;
}

MyString MyString::operator +(const MyString& obj) const
{
	MyString o;
	o.length = length + obj.length;
	o.tab = new char[o.length + 1];
	strcpy(o.tab, tab);
	strcat(o.tab, obj.tab);
	return o;
}

MyString MyString::operator +(const char c) const
{
	MyString o;
	o.length = length + 1;
	o.tab = new char[o.length + 1];
	strcpy(o.tab, tab);
	o.tab[o.length - 1] = c;
	o.tab[o.length] = '\0';
	return o;
}

MyString MyString::operator *(int n) const
{
	MyString obj;
	obj.length = length * n;
	obj.tab = new char[obj.length + 1];
	strcpy(obj.tab, tab);
	for(int i = 1; i < n; i++)
	{
		strcat(obj.tab, tab);
	}
	return obj;
}

void MyString::operator =(const MyString& obj)
{
	delete[] tab;
	tab = new char[obj.length + 1];
	length = obj.length;
	strcpy(tab, obj.tab);
}
bool MyString::operator ==(const MyString& obj) const
{
	return !strcmp(obj.tab, tab);
}

char& MyString::operator [](int n) const
{
	return tab[n];
}

ostream& operator <<(ostream& os, const MyString& obj)
{
	return os << obj.tab;
}

MyString operator *(int n, const MyString& obj)
{
 	return obj * n;
}

