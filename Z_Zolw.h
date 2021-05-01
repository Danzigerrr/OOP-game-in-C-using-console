#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {

public:
	Zolw();
	Zolw(Swiat* swiat, COORDINATES pos, int wiek);

	void Akcja() override;
	void Kolizja(Organizm* o) override;
	~Zolw();
};
