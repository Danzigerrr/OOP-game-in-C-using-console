#include "R_Mlecz.h"
#define ILOSC_PROB_ROZPRZEST 3

Mlecz::Mlecz() {}
Mlecz::Mlecz(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 0;
	this->swiat = swiat;
	this->pozycja = pos;
}

Mlecz::~Mlecz() {}

const char Mlecz::GetZnak() { return MLECZ; }
void Mlecz::Kolizja(Organizm* o) {}

void Mlecz::Akcja() {
	for (int i = 0; i < ILOSC_PROB_ROZPRZEST; i++) {

	}
}



