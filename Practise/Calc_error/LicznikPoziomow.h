#pragma once

//Klasa LicznikPoziomow odpowiedzialna za zliczanie poziomow
class LicznikPoziomow
{
public:
	//Konsturktor zwiekszajacy zmienna level o 1 przy tworzeniu nowego obiektu
	LicznikPoziomow();
	//Destruktor zmniejszajacy zmienna level o 1 przy niszczeniu obiektu
	~LicznikPoziomow();
private:
	static int level;
};
