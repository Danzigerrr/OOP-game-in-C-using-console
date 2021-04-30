#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	virtual void Split();
public:
	Zwierze();
	Zwierze(Swiat* swiat, const COORDINATES pos);
	Zwierze(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);


	void Akcja() override;
	void Kolizja() override;
	const void Rysuj() override;

	virtual void Split(Organizm*); ///?

	const char GetZnak() override;

	~Zwierze();
};
