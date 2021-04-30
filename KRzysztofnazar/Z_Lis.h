#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
private:
	void Split() override;

public:
	Lis();
	Lis(Swiat* swiat, const COORDINATES pos);
	Lis(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);

	const void Rysuj() override;
	const char GetZnak() override;

	~Lis();
};