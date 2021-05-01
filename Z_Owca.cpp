#include "Z_Owca.h"
#include "Swiat.h"

Owca::Owca() {
	this->sila = 4;
	this->inicjatywa = 4;
    this->znak = OWCA;
}
Owca::Owca(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 4;
	this->inicjatywa = 4;
    this->znak = OWCA;
	this->swiat = swiat;
	this->pozycja = pos;
}

Owca::~Owca() {}

