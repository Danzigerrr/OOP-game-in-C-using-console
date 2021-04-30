#pragma once
#include "Roslina.h"

class Trawa : public Roslina {

public:
	Trawa();
	Trawa(Swiat* swiat, const COORDINATES pos);
	Trawa(Swiat* swiat, const COORDINATES pos, int wiek, int sila);

	const void Rysuj() override;
	const char GetZnak() override;

	~Trawa();
};
