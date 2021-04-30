#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
private:
	void Split() override;

public:
	Antylopa();
	Antylopa(Swiat* swiat, const COORDINATES pos);
	Antylopa(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);

	const void Rysuj() override;
	const char GetZnak() override;

	~Antylopa();
};
