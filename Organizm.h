#pragma once
#include "Defines.h"

class Organizm {
protected:
	int sila;
	int inicjatywa;
	COORDINATES pozycja;
	int wiek = 0;
	Swiat* swiat;
	int step = 1;
	virtual void Kolizja(Organizm* o);
	char znak;
public:
	Organizm();

	virtual void Akcja() = 0;  //abstakcyjna bo rozna dla zwierzat i roslin
	virtual void SprawdzKolizje(DIRECTION dir);
	virtual DIRECTION ZrobRuch();
	
	void nadajSwiat(Swiat* s);
	void nadajPozycje(int x, int y);

	const char GetZnak();
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

	~Organizm();
	
};

bool cmp(Organizm* o1, Organizm* o2);
