#include "Z_Owca.h"
#include "Swiat.h"

Owca::Owca() {
	init();
}
Owca::Owca(Swiat* swiat, COORDINATES pos, int wiek) {
	init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;
}


Owca::~Owca() {}

void Owca::init() {
	this->sila = 4;
	this->inicjatywa = 4;
	this->znak = OWCA;
}
