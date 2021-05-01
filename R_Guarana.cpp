#include "R_Guarana.h"



Guarana::Guarana() {
	this->sila = 0;
	this->znak = GUARANA;
}
Guarana::Guarana(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 0;
	this->znak = GUARANA;
	this->swiat = swiat;
	this->pozycja = pos;
}

Guarana::~Guarana() {}

void Guarana::Kolizja(Organizm* o) {}

void Guarana::Akcja() {

}



