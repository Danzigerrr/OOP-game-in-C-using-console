#pragma once
#include "Roslina.h"

class Mlecz : public Roslina {
private:
	void init() override;
public:
	Mlecz();
	Mlecz(Swiat* swiat, const COORDINATES pos, int wiek);

	void Akcja() override;

	~Mlecz();
};