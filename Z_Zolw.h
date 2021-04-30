#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
private:
	void Split() override;

public:
	Zolw();
	Zolw(Swiat* swiat, const COORDINATES pos);
	Zolw(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);

	const void Rysuj() override;
	const char GetZnak() override;

	~Zolw();
};
