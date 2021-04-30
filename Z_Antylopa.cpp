#include "Z_Antylopa.h"

Antylopa::Antylopa() {}
Antylopa::Antylopa(Swiat* swiat, const COORDINATES pos, int wiek, int inicjatywa, int sila)
	: Zwierze(swiat, pos, wiek, inicjatywa, sila) {}

Antylopa::~Antylopa() {}

const char Antylopa::GetZnak() {
	return ANTYLOPA;
}

void Antylopa::Akcja() {

}