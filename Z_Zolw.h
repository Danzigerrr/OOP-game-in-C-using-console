#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze {
private:
	void Split() override;

public:
	Zolw();
	Zolw(Swiat* swiat, COORDINATES pos, int wiek, int inicjatywa, int sila);


	const char GetZnak() override;
	void Akcja() override;


	~Zolw();
};
