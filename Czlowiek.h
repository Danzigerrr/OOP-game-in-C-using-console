#pragma once
#include "Zwierze.h"
#include "Swiat.h"

class Czlowiek : public Zwierze {
private:
	int UmiejAktywnaPrzez;
	int UmiejOdnawianaPrzez;
	int KierunekRuchuCzlowieka;
	void KolizjaZAktywnaUmiejetnoscia(Zwierze* atakujacy, DIRECTION dir);
	void init() override;
	DIRECTION ZrobRuch() override;
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