#pragma once
#include "Zwierze.h"
#include <iostream>
using namespace std;

class Czlowiek : public Zwierze {

public:
	Czlowiek();
	Czlowiek(Swiat* swiat, const COORDINATES pos);
	Czlowiek(Swiat* swiat, const COORDINATES, int wiek, int inicjatywa, int sila);

	void Akcja() override;
	void Kolizja() override;
	void const Rysuj() override;
	const char GetZnak() override;

	~Czlowiek();

};