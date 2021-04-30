#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa();
	Antylopa(Swiat* swiat, COORDINATES coor, int wiek, int inicjatywa, int sila);

	const char GetZnak() override;
	void Akcja() override;

	~Antylopa();
};
