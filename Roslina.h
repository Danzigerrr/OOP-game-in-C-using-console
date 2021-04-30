#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	virtual void Split();
	Organizm* nastepny(const DIRECTION kierunek, const int distnace);
public:
	Roslina();
	Roslina(Swiat* swiat, int x, int y, int wiek, int inicjatywa, int sila);

	void Akcja() override;
	void Kolizja() override;
	const void Rysuj() override;
	const char GetZnak() override;
	~Roslina();

};
