#pragma once
#include "Roslina.h"
class Mlecz : public Roslina {
private:
	void Split() override;

public:
	Mlecz();
	Mlecz(Swiat* swiat, const COORDINATES pos);
	Mlecz(Swiat* swiat, const COORDINATES pos, int wiek, int sila);

	const void Rysuj() override;
	const char GetZnak() override;
	void Akcja() override;

	~Mlecz();
};