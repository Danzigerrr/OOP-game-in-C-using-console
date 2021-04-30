#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {
private:
	void Split() override;

public:
	WilczeJagody();
	WilczeJagody(Swiat* swiat, const COORDINATES pos);
	WilczeJagody(Swiat* swiat, const COORDINATES pos, int wiek, int sila);

	const void Rysuj() override;
	const char GetZnak() override;
	void Kolizja() override;

	~WilczeJagody();
};
