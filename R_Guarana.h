#pragma once
#include "Roslina.h"
class Guarana : public Roslina {
private:
	void Split() override;

public:
	Guarana();
	Guarana(Swiat* swiat, const COORDINATES pos, int wiek);

	virtual void Akcja() override;

	void Kolizja(Organizm* o) override;

	~Guarana();
};
