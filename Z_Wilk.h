#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
private:
	void Split() override;

public:
	Wilk();
	Wilk(Swiat* swiat, COORDINATES coor, int wiek);

	const char GetZnak() override;
	void Akcja() override;
	void Kolizja(Organizm* o) override;
	~Wilk();
};
