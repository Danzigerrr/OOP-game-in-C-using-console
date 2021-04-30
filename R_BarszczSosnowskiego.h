#pragma once
#include "Roslina.h"



class BarszczSosnowskiego : public Roslina {
private:
	void Split() override;

public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(Swiat* swiat, const COORDINATES pos, int wiek);

	virtual void Akcja() override;
	const char GetZnak() override;
	void Kolizja(Organizm* o) override;

	~BarszczSosnowskiego();
};