#pragma once
#include "Roslina.h"



class BarszczSosnowskiego : public Roslina {
private:
	void Split() override;

public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos);
	BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos, int wiek, int sila);

	const void Rysuj() override;
	const char GetZnak() override;
	void Akcja() override;
	void Kolizja() override;

	~BarszczSosnowskiego();
};