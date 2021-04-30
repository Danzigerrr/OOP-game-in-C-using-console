#include "Z_Wilk.h"

Wilk::Wilk(){}
Wilk::Wilk(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 9;
	this->inicjatywa = 5;
	this->swiat = swiat;
	this->pozycja = pos;
}

Wilk::~Wilk() {}

const char Wilk::GetZnak() {
	return WILK;
}

void Wilk::Akcja() {

}