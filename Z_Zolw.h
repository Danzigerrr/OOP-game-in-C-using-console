#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
private:
	void Split() override;

public:
	Zolw();
	Zolw(Swiat* swiat, COORDINATES pos, int wiek);

	const char GetZnak() override;
	void Akcja() override;
	void Kolizja(Organizm* o) override;
	~Zolw();
};
