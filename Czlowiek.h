#pragma once
#include "Zwierze.h"
#include <iostream>
using namespace std;

class Czlowiek : public Zwierze {
private:
	int UmiejetnoscAktywnaPrzez;
	int UmiejetnoscOdnawianaPrzez;
public:
	Czlowiek();
	Czlowiek(Swiat* swiat, const COORDINATES, int wiek);

	const char GetZnak() override;
	void Akcja() override;
	void Kolizja(Organizm* o) override;
	~Czlowiek();
};