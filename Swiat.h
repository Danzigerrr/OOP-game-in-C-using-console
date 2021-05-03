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


class Swiat
{
private:
	int wysokosc, szerokosc;
	int tura;
	Organizm*** plansza;
	bool cmp(Organizm*o1, Organizm* o2);
	int get_value_from_char(char* tab, int* iterator); //do wczytania z pliku
	
	void PrzygotujKolejnaRunde();
public:
	vector<Organizm*> wezWszystkieOrganizmy();

	Swiat(const int width, const int height);
	~Swiat();
void RysujSwiat(); //potem wrzuc do private
	Organizm* GetPole(COORDINATES coor);

	void WykonajTure();

	void WczytajSwiatZPliku();
	
	int GetWysokosc();
	int GetSzerokosc();
	int GetTura();
	void GetHumanCommand();
	Organizm* GetHuman();

	Organizm*** GetPlansza();
	void SetPlansza(Organizm*** plansza);
	void SetPole(COORDINATES coor, Organizm* org);
	void testuj();
};

