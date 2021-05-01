#include "Z_Zolw.h"

Zolw::Zolw() {
	this->sila = 2;
	this->inicjatywa = 1;
}
Zolw::Zolw(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 2;
	this->inicjatywa = 1;
	this->swiat = swiat;
	this->pozycja = pos;
}

Zolw::~Zolw() {}

const char Zolw::GetZnak() {
	return ZOLW;
}

void Zolw::Akcja() {

}

void Zolw::Kolizja(Organizm* atakujacy) {
     delete this;
}