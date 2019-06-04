#pragma once

//Klasa AttFormat odpowiedzialna za format tekstu
class AttFormat
{
public:
	//Domyslny konstruktor i wirtualny desktruktor
	AttFormat() = default;
	virtual ~AttFormat() = default;

	//Typ wyliczeniowy przechowujacy dostepne formaty
	enum Option
	{
		BOLD, 
		DIM, 
		UNDERLINED, 
		RESET, 
	};

	//Metoda zwracajaca aktualnie przechowywany format
	const Option getFormat() const { return m_format; }
	//Metoda ustawiajaca format w zmiennej m_format
	void setFormat(Option opt) { m_format = opt; }
	
private:
	Option m_format;
};
