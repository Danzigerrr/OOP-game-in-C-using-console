#include "R_Guarana.h"
#include "Swiat.h"
#define ZWIEKSZENIE_SILY 3

Guarana::Guarana() {
	init();
}
Guarana::Guarana(Swiat* swiat, const COORDINATES pos, int wiek) {
	init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

void Guarana::init() {
	this->sila = 0;
	this->znak = GUARANA;
}

Guarana::~Guarana() {}

void Guarana::Kolizja(Zwierze* atakujacy, DIRECTION dir)
{

    if (sila != atakujacy->GetSila()) //sily sa rozne --> wygyrwa silniejszy
    {
        if (sila > atakujacy->GetSila()) //wygrywa obronca
        {
            ObroncaWygral(atakujacy, dir);
        }
        else //wygrywa atakujacy
        {
            AtakujacyWygral(atakujacy, dir);
            int obecnaSilaAtak = atakujacy->GetSila();
            atakujacy->SetSila(obecnaSilaAtak + ZWIEKSZENIE_SILY);
        }
    }

    else //jesli sily sa rowne --> wygrywa atakujacy
    {
        AtakujacyWygral(atakujacy, dir);
        int obecnaSilaAtak = atakujacy->GetSila();
        atakujacy->SetSila(obecnaSilaAtak + ZWIEKSZENIE_SILY);
    }
}





