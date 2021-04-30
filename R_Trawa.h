#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
private:
	void Split() override;

public:
	Trawa();
	Trawa(Swiat* swiat, const COORDINATES pos, int wiek);

	virtual void Akcja() override;
	const char GetZnak() override;
	void Kolizja(Organizm* o) override;

	~Trawa();
};
