#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
private:
	void Split() override;

public:
	Owca();
	Owca(Swiat* swiat, COORDINATES pos, int wiek);


	const char GetZnak() override;
	void Akcja() override;
	void Kolizja(Organizm* o) override;

	~Owca();
};