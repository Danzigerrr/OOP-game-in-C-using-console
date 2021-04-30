#include "Z_Lis.h"


Lis::Lis() {}
Lis::Lis(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 3;
	this->inicjatywa = 7;
	this->swiat = swiat;
	this->pozycja = pos;
}

Lis::~Lis() {}

const char Lis::GetZnak() {
	return LIS;
}

void Lis::Akcja() {

}