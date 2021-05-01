#include "R_WilczeJagody.h"

WilczeJagody::WilczeJagody() {
	this->sila = 99;
	this->znak = WILCZEJAGODY;

}
WilczeJagody::WilczeJagody(Swiat* swiat, const COORDINATES pos, int wiek) {
	this->wiek = wiek;
	this->sila = 99;
	this->znak = WILCZEJAGODY;
	this->swiat = swiat;
	this->pozycja = pos;
}

WilczeJagody::~WilczeJagody() {}
void WilczeJagody::Kolizja(Organizm* o) { }


void WilczeJagody::Akcja() {

}


