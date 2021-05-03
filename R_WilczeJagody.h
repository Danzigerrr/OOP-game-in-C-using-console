#pragma once
#include "TrujacaRoslina.h"

class WilczeJagody : public TrujacaRoslina {
private:
	void init() override;

public:
	WilczeJagody();
	WilczeJagody(Swiat* swiat, const COORDINATES pos, int wiek);

	void Kolizja(Zwierze* atakujacy, DIRECTION dir) override;

	~WilczeJagody();
};
