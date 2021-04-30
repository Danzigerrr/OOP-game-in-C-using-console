#include "Z_Zolw.h"

Zolw::Zolw() {}
Zolw::Zolw(Swiat* swiat, const COORDINATES pos, int wiek, int inicjatywa, int sila)
	: Zwierze(swiat, pos, wiek, inicjatywa, sila) {}

Zolw::~Zolw() {}

const char Zolw::GetZnak() {
	return ZOLW;
}

void Zolw::Akcja() {

}