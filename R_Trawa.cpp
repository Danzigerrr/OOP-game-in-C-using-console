#include "R_Trawa.h"

Trawa::Trawa() {
	this->sila = 0;
}
Trawa::Trawa(Swiat* swiat, const COORDINATES position, int wiek)
{
	this->wiek = wiek;
	this->sila = 0;
	this->swiat = swiat;
	this->pozycja = position;
}

const char Trawa::GetZnak() { return TRAWA; }
void Trawa::Kolizja(Organizm* o) {}
void Trawa::Akcja() {}

Trawa::~Trawa() {}
