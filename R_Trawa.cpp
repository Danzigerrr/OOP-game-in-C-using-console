#include "R_Trawa.h"

Trawa::Trawa() {
	init();

}
Trawa::Trawa(Swiat* swiat, const COORDINATES position, int wiek)
{
	init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = position;
}


void Trawa::init() {
	this->sila = 0;
	this->znak = TRAWA;
}



Trawa::~Trawa() {}
