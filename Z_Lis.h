#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
private:
	void Split() override;

public:
	Lis();
	Lis(Swiat* swiat, COORDINATES pos, int wiek, int inicjatywa, int sila);

	const char GetZnak() override;
	void Akcja() override;


	~Lis();
};