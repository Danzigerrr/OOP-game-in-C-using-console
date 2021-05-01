#include "R_Trawa.h"

Trawa::Trawa() {
	this->sila = 0;
	this->znak = TRAWA;

}
Trawa::Trawa(Swiat* swiat, const COORDINATES position, int wiek)
{
	this->wiek = wiek;
	this->sila = 0;
	this->znak = TRAWA;

	this->swiat = swiat;
	this->pozycja = position;
}

void Trawa::Kolizja(Organizm* o) {}
void Trawa::Akcja() {}

Trawa::~Trawa() {}
