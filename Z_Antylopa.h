#pragma once
#include "Zwierze.h"
#include "Swiat.h"
class Antylopa : public Zwierze {

public:
	Antylopa();
	Antylopa(Swiat* swiat, COORDINATES coor, int wiek);

	void Akcja() override;
	void Kolizja(Organizm* o) override;
	~Antylopa();
};
