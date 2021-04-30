#include "Z_Owca.h"


Owca::Owca() {}
Owca::Owca(Swiat* swiat, const COORDINATES pos, int wiek, int inicjatywa, int sila)
	: Zwierze(swiat, pos, wiek, inicjatywa, sila) {}

Owca::~Owca() {}

const char Owca::GetZnak() {
	return OWCA;
}

void Owca::Akcja() {

}