#include "Czlowiek.h"
Czlowiek::Czlowiek() {}
Czlowiek::Czlowiek(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 5;
	this->inicjatywa = 4;
	this->swiat = swiat;
	this->pozycja = pos;
}


Czlowiek::~Czlowiek() {}

const char Czlowiek::GetZnak() {
	return CZLOWIEK;
}

void Czlowiek::Akcja() {

}

void Czlowiek::Kolizja(Organizm* o) {

}