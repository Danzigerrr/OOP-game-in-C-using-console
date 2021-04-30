#include "R_WilczeJagody.h"

WilczeJagody::WilczeJagody() {}
WilczeJagody::WilczeJagody(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 99;
	this->swiat = swiat;
	this->pozycja = pos;
}

WilczeJagody::~WilczeJagody() {}
void WilczeJagody::Kolizja(Organizm* o) { }
const char WilczeJagody::GetZnak() { return WILCZEJAGODY; }

void WilczeJagody::Akcja() {

}


