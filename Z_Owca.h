#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
private:
	void Split() override;

public:
	Owca();
	Owca(Swiat* swiat, const COORDINATES pos);
	Owca(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);

	const void Rysuj() override;
	const char GetZnak() override;

	~Owca();
};