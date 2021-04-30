#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
	void Split() override;
public:
	Antylopa();
	Antylopa(Swiat* swiat, COORDINATES coor, int wiek);

	const char GetZnak() override;
	void Akcja() override;
	void Kolizja(Organizm* o) override;
	~Antylopa();
};
