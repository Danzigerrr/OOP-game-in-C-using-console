#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
private:
	void Split() override;

public:
	Lis();
	Lis(Swiat* swiat, COORDINATES pos, int wiek);

	const char GetZnak() override;
	void Akcja() override;
	void Kolizja(Organizm* o) override;

	~Lis();
};