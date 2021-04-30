#include "Z_Wilk.h"

Wilk::Wilk(){}
Wilk::Wilk(Swiat* swiat, const COORDINATES pos, int wiek, int inicjatywa, int sila)
	: Zwierze(swiat, pos, wiek, inicjatywa, sila) {}

Wilk::~Wilk() {}

const char Wilk::GetZnak() {
	return WILK;
}

void Wilk::Akcja() {

}