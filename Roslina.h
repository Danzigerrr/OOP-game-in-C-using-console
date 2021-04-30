#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	virtual void Split() = 0;
	Organizm* nastepny(const DIRECTION kierunek, const int distnace);
public:
	Roslina();
	Roslina(Swiat* swiat, COORDINATES coor, int wiek, int sila);

	virtual void Akcja() override;
	void Kolizja(Organizm* o) override; //do private?

	virtual const char GetZnak() override;

	~Roslina();

};
