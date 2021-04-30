#pragma once
#include "Defines.h"

class Organizm {
protected:
	int sila;
	int inicjatywa;
	COORDINATES pozycja;
	int wiek;
	Swiat* swiat;
public:
	Organizm();

	virtual void Akcja() = 0;  // akcja trigerruje kolizje jesli jest problem
	virtual void Kolizja(Organizm* o) = 0;
	void nadajSwiat(Swiat* s);
	void nadajPozycje(int x, int y);

	virtual const char GetZnak() = 0;
	int GetWiek();
	int GetInicjatywa();
	int GetSila();
	COORDINATES GetPozycja();


	~Organizm();
};

bool cmp(Organizm* o1, Organizm* o2);
