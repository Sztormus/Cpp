#pragma once

//Klasa AttColor odpowiadajaca za kolor tekstu
class AttColor
{
public:
	//Domyslny konstruktor i wirtualny destruktor
	AttColor() = default;
	virtual ~AttColor() = default;

	//Typ wyliczeniowy przechowujacy nazwy dostepnych kolorow
	enum Option
	{
		BLACK, 
		RED, 
		GREEN, 
		YELLOW, 
		BLUE, 
		MAGENTA, 
		CYAN, 
		GRAY, 
		WHITE, 
		RESET,
	};
	
	//Metoda zwracajaca aktualnie wybrany kolor
	const Option getColor() const { return m_color; }
	//Metoda ustawiacajaca kolor do zmiennej m_color
	void setColor(Option opt) { m_color = opt; }
private:
	Option m_color;
};
