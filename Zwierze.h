#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	virtual void Split() = 0;
public:
	Zwierze();
	//Zwierze(Swiat* swiat, COORDINATES coor, int wiek); // do wczytania z pliku

	virtual void Akcja() override;

	void Kolizja(Organizm* o) override; //do private?

	virtual const char GetZnak() override;
	~Zwierze();
};
