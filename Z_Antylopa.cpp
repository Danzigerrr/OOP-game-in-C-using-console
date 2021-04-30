#include "Z_Antylopa.h"

Antylopa::Antylopa() {}
Antylopa::Antylopa(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 4;
	this->inicjatywa = 4;
	this->swiat = swiat;
	this->pozycja = pos;
}

Antylopa::~Antylopa() {}

const char Antylopa::GetZnak() { return ANTYLOPA; }

void Antylopa::Akcja() {

}