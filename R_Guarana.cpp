#include "R_Guarana.h"



Guarana::Guarana() {}
Guarana::Guarana(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 0;
	this->swiat = swiat;
	this->pozycja = pos;
}

Guarana::~Guarana() {}

const char Guarana::GetZnak() { return GUARANA; }
void Guarana::Kolizja(Organizm* o) {}

void Guarana::Akcja() {

}



