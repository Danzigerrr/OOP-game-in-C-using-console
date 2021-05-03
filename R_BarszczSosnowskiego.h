#pragma once
#include "TrujacaRoslina.h"



class BarszczSosnowskiego : public TrujacaRoslina {
private:
	void init() override;
	void zabijSasiada(COORDINATES coor);

public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos, int wiek);

	void Akcja() override;

	void Kolizja(Zwierze* o, DIRECTION dir) override;

	~BarszczSosnowskiego();
};