#pragma once
#include "Defines.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Czlowiek.h"
#include "R_BarszczSosnowskiego.h"
#include "R_Guarana.h"
#include "R_Mlecz.h"
#include "R_Trawa.h"
#include "R_WilczeJagody.h"
#include "Z_Antylopa.h"
#include "Z_Lis.h"
#include "Z_Owca.h"
#include "Z_Wilk.h"
#include "Z_Zolw.h"
#define ILOSC_ORGANIZMU_NA_POCZATKU 20 //%
class Organizm;

class Swiat
{
private:
	int wysokosc, szerokosc;
	int tura;
	Organizm*** plansza;
	int iloscOrgNaPoczatku = ILOSC_ORGANIZMU_NA_POCZATKU;
	void PrzygotujKolejnaRunde();
	
	string ZapiszPoczatkowySwiat();
	Organizm* StworzOrganizmTegoGatunku(char gatunek, COORDINATES coor, int wiek);
	void WczytajOrganizmyZPliku(FILE* fptr);
	void WczytajInfoOSwiecieZPliku(FILE* fptr);
	void UtworzPlanszeZPliku();
	char* WczytajNazwePliku();
	void GetHumanCommand();
	bool SprawdzCzySaAktywneOrganizmy();
	Organizm* GetHuman();
	vector<Organizm*> wezWszystkieOrganizmy(bool TylkoAktywne = false);

	int get_value_from_char(char* tab, int* iterator); //do wczytania z pliku
public:
	void RysujSwiat(); //potem wrzuc do private
	Swiat();
	Swiat(const int width, const int height);
	~Swiat();

	void WczytajSwiatZPliku();

	void WykonajTure();
	void ZapiszSwiatDoPliku();
	int GetWysokosc();
	int GetSzerokosc();
	int GetTura();

	void SetPole(COORDINATES coor, Organizm* org);
	Organizm* GetPole(COORDINATES coor);
};
bool cmp(Organizm* o1, Organizm* o2);

