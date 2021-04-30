#include "Z_Owca.h"


Owca::Owca() {}
Owca::Owca(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 4;
	this->inicjatywa = 4;
	this->swiat = swiat;
	this->pozycja = pos;
}


Owca::~Owca() {}

const char Owca::GetZnak() {
	return OWCA;
}

void Owca::Akcja() {

}