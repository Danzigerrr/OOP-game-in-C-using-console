#include "R_Trawa.h"

Trawa::Trawa() {}
Trawa::Trawa(Swiat* swiat, const COORDINATES position, int wiek, int sila)
{
	this->wiek = wiek;
	this->sila = sila;
	this->swiat = swiat;
	this->pozycja = position;
}

const void Trawa::Rysuj() { cout << TRAWA; }
const char Trawa::GetZnak() { return TRAWA; }

Trawa::~Trawa() {}