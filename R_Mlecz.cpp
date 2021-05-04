#include "R_Mlecz.h"
#include "Swiat.h"
#define ILOSC_PROB_ROZPRZEST 3

Mlecz::Mlecz() {
	init();
}
Mlecz::Mlecz(Swiat* swiat, const COORDINATES pos, int wiek) {
	init();
	this->wiek = wiek;
	this->swiat = swiat;
	this->pozycja = pos;

}

Mlecz::~Mlecz() {}

void Mlecz::init() {
	this->sila = 0;
	this->znak = MLECZ;
}


void Mlecz::Akcja() {
	for (int i = 0; i < ILOSC_PROB_ROZPRZEST; i++) {
		//cout << "proba rozsiania Mlecza nr" << i + 1 << endl;
		NormalnaAkcjaRoslin();
	}

}



