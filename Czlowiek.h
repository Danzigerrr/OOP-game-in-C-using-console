#pragma once
#include "Zwierze.h"
#include <iostream>
using namespace std;

class Czlowiek : public Zwierze {
private:
	int UmiejetnoscAktywnaPrzez;
	int UmiejetnoscOdnawianaPrzez;
	int KierunekRuchuCzlowieka;
	void KolizjaZAktywnaUmiejetnoscia(Zwierze* atakujacy, DIRECTION dir);
	void init() override;
public:
	Czlowiek();
	Czlowiek(Swiat* swiat, const COORDINATES, int wiek);
	int GetUmiejetnoscAktywnaPrzez();
	void SetUmiejetnoscAktywnaPrzez(int value);
	int GetUmiejetnoscOdnawianaPrzez();
	void SetUmiejetnoscOdnawianaPrzez(int value);
	void SetKierunekRuchuCzlowieka(int dir);
	void Akcja() override;
	void Kolizja(Zwierze* o, DIRECTION dir) override;
	~Czlowiek();


};