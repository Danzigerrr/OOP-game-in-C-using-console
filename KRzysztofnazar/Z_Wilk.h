#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
private:
	void Split() override;

public:
	Wilk();
	Wilk(Swiat* swiat, const COORDINATES pos);
	Wilk(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);

	const void Rysuj() override;
	const char GetZnak() override;

	~Wilk();
};