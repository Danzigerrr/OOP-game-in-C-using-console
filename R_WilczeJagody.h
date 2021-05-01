#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {
private:
	void Split() override;

public:
	WilczeJagody();
	WilczeJagody(Swiat* swiat, const COORDINATES pos, int wiek);

	virtual void Akcja() override;

	void Kolizja(Organizm* o) override;

	~WilczeJagody();
};
