#pragma once
#include "Roslina.h"



class BarszczSosnowskiego : public Roslina {
private:
	void init() override;
public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos, int wiek);

	void Akcja() override;

	void Kolizja(Zwierze* o, DIRECTION dir) override;

	~BarszczSosnowskiego();
};