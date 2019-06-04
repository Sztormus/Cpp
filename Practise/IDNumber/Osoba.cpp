#include "Osoba.h"
#include <iostream>

Osoba::Osoba(std::string _name): name(_name) {}

std::ostream& operator << (std::ostream& os, const Osoba& obj)
{
	return os << obj.name << obj.GetStatus();
}

Student::Student(std::string name, NumerId id): Osoba(name), index(id) {}

const NumerId& Student::numId() const
{
	return index;
}

const std::string Student::GetStatus() const
{
	return " - student";
}

Dydaktyk::Dydaktyk(std::string name, NumerId id): Osoba(name), index(id) {}

const NumerId& Dydaktyk::numId() const
{
	return index.numId();
}

const std::string Dydaktyk::GetStatus() const
{
	return " - dydaktyk";
}


Wozny::Wozny(std::string name): Osoba(name) {}

const std::string Wozny::GetStatus() const
{
	return " - wozny";
}


Doktorant::Doktorant(std::string name, NumerId id_dydaktyk, NumerId id_student): Osoba(name), Student(name, id_student), Dydaktyk(name, id_dydaktyk) {}

const NumerId& Doktorant::numId_uczen() const
{
	return Student::numId();
}

const NumerId& Doktorant::numId_nauczyciel() const
{
	return Dydaktyk::numId();
}

const std::string Doktorant::GetStatus() const
{
	return " - doktorant";
}

