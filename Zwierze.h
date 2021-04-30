#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	virtual void Split();
public:
	Zwierze();
	Zwierze(Swiat* swiat, COORDINATES coor, int wiek, int inicjatywa, int sila); // do wczytania z pliku

	virtual void Akcja() override;

	void Kolizja(Organizm* o) override; //do private?

	virtual const char GetZnak() = 0;
	~Zwierze();
};
