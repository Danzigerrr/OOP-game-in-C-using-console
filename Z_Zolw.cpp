#include "Z_Zolw.h"
#include "Swiat.h"
Zolw::Zolw() {
	this->sila = 2;
	this->inicjatywa = 1;
	this->znak = ZOLW;
}
Zolw::Zolw(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->sila = 2;
	this->inicjatywa = 1;
	this->znak = ZOLW;
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}

Zolw::~Zolw() {}


void Zolw::Akcja() {
	int SzansaNaRuch = rand() % 3; // w 75% zolw nie zmienia swojego polozenia
	if (SzansaNaRuch) {
		DIRECTION dir = ZrobRuch();
		SprawdzKolizje(dir);
	}
}

void Zolw::Kolizja(Organizm* atakujacy) {
     delete this;
}