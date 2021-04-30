#pragma once
#include "Defines.h"

class Organizm {

public:
	int sila;
	int inicjatywa;
	COORDINATES pozycja;
	int wiek;
	Swiat* swiat;

	Organizm();
	Organizm(Swiat* swiat, const COORDINATES pos);
	Organizm(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);

	virtual void Akcja() = 0;
	virtual void Kolizja() = 0;
	virtual const void Rysuj() = 0;

	virtual void Split(Organizm*);

	virtual const char GetZnak();
	int GetWiek();
	int GetInicjatywa();
	int GetSila();
	COORDINATES GetPozycja();

	~Organizm();
};


