#pragma once

//Klasa MapPoint ktora przedstawia punkt na mapie
class MapPoint
{
private:

	//Deklaracja zmiennych
	static int number;
	double d_lat;
	double d_lon;

	//Pomocnicza metoda wyswietlajaca ilosc stworzonych punktow 
	void Number_of_Points(int n) const;

public:

	//Kontruktor wypelniajacy zmienne d_lat i d_lom, zwiekszajacy zmienna number o 1 
	//i wypisujacy te dane na ekran
	MapPoint(const double lat, const double lon);

	//Dektruktor zmniejszajacy zmienna number o 1 i wyswietlacy jej zawartosc na ekran
	~MapPoint();

	//Metoda liczaca odleglosc miedzy podanymi wspolrzednymi
	//(w uproszczony sposob - z twierdzenia Pitagorasa)
	double odleglosc(double x1, double y1, double x2, double y2) const;

	//Metoda przesuwajaca wsporzednie punktu o argumenty zawarte w metodzie
	void move(const double lat, const double lon);

	//Metoda wyswietlajaca dane punktu na ekran
	void print() const;

	//Metoda zwracajaca referencje do punkty ktory znajduje sie dalej od obecnego punktu
	const MapPoint &furtherFrom(const MapPoint &A, const MapPoint &B) const;

	//Statyczna metoda tworzaca punkt posrodku dwoma punktami podanymi jak argumenty metody
	static MapPoint inTheMiddle(const MapPoint &A, const MapPoint &B);
};