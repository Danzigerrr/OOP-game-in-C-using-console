#pragma once
#include "Zwierze.h"
#include <iostream>
using namespace std;

class Czlowiek : public Zwierze {
private:
	int UmiejetnoscAktywnaPrzez;
	int UmiejetnoscOdnawianaPrzez;
	void Split() override;
public:
	Czlowiek();
	Czlowiek(Swiat* swiat, const COORDINATES, int wiek);
	int GetUmiejetnoscAktywnaPrzez();
	void SetUmiejetnoscAktywnaPrzez(int value);
	int GetUmiejetnoscOdnawianaPrzez();
	void SetUmiejetnoscOdnawianaPrzez(int value);
	const char GetZnak() override;
	void Akcja() override;
	void Kolizja(Organizm* o) override;
	~Czlowiek();


};