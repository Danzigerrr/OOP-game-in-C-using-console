#pragma once
#include "Defines.h"
#include "Organizm.h"
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
	Organizm ***plansza;
	
public:

	Swiat(const int width, const int height);
	~Swiat();

	void RysujSwiat();

	void WykonajTure();

	void DodajOrganizm(); 
	/*
	* sortowanie po dwoch zmiennych w wektorze:
	* https://stackoverflow.com/questions/6771374/sorting-an-stl-vector-on-two-values
	*/
};

