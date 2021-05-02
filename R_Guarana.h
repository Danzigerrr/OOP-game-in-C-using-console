#pragma once
#include "Roslina.h"
class Guarana : public Roslina {
private:
	void init() override;
public:
	Guarana();
	Guarana(Swiat* swiat, const COORDINATES pos, int wiek);

	void Kolizja(Zwierze* o, DIRECTION dir) override;
	~Guarana();
};
