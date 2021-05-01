#pragma once
#include "Defines.h"
#include "Swiat.h"
class Organizm {
protected:
	int sila;
	int inicjatywa;
	COORDINATES pozycja;
	int wiek = 0;
	Swiat* swiat;
public:
	Organizm();

	virtual void Akcja() = 0;  // akcja trigerruje kolizje jesli jest problem
	virtual void Kolizja(Organizm* o);
	void nadajSwiat(Swiat* s);
	void nadajPozycje(int x, int y);

	virtual const char GetZnak() = 0;
	int GetWiek();
	void SetWiek(int wiek);
	int GetInicjatywa();
	void SetInicjatywa(int inicjatywa);
	int GetSila();
	void SetSila(int sila);
	Swiat* GetSwiat();
	void SetSwiat(Swiat *swiat);
	COORDINATES GetPozycja();
	void SetPozycja(COORDINATES pos);

	void SprawdzKolizje();

	~Organizm();
};

bool cmp(Organizm* o1, Organizm* o2);
