#include "Z_Wilk.h"
#include "Swiat.h"
Wilk::Wilk(){
	this->sila = 9;
	this->inicjatywa = 5;
    this->znak = WILK;
}
Wilk::Wilk(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->sila = 9;
	this->inicjatywa = 5;
    this->znak = WILK;
    this->wiek = wiek;
    this->swiat = swiat;
    this->pozycja = pos;
}

Wilk::~Wilk() {}
