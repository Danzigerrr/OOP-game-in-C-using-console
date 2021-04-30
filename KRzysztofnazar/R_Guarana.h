#pragma once
#include "Roslina.h"
class Guarana : public Roslina {
private:
	void Split() override;

public:
	Guarana();
	Guarana(Swiat* swiat, const COORDINATES pos);
	Guarana(Swiat* swiat, const COORDINATES pos, int wiek, int sila);

	const void Rysuj() override;
	const char GetZnak() override;
	void Kolizja() override;

	~Guarana();
};
