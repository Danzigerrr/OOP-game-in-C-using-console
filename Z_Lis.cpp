#include "Z_Lis.h"


Lis::Lis() {}
Lis::Lis(Swiat* swiat, const COORDINATES pos, int wiek, int inicjatywa, int sila)
	: Zwierze(swiat, pos, wiek, inicjatywa, sila) {}

Lis::~Lis() {}

const char Lis::GetZnak() {
	return LIS;
}

void Lis::Akcja() {

}